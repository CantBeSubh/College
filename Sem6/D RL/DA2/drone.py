import gym
import numpy as np
import torch
import torch.nn as nn
import torch.optim as optim
from torch.distributions import Categorical
from torch.utils.data.sampler import BatchSampler, SubsetRandomSampler
print(gym.__version__)
class ActorCritic(nn.Module):
    def __init__(self):
        super(ActorCritic, self).__init__()
        self.fc1 = nn.Linear(2, 64)
        self.fc2 = nn.Linear(64, 64)
        self.fc3 = nn.Linear(64, 2)
        self.fc4 = nn.Linear(64, 1)
        self.optimizer = optim.Adam(self.parameters(), lr=0.001)
        
    def forward(self, x):
        x = torch.relu(self.fc1(x))
        x = torch.relu(self.fc2(x))
        logits = self.fc3(x)
        value = self.fc4(x)
        return logits, value
    
    def choose_action(self, state):
        state = torch.from_numpy(state).float()
        logits, _ = self.forward(state)
        prob = nn.functional.softmax(logits, dim=-1)
        m = Categorical(prob)
        action = m.sample()
        return action.item(), prob[:, action]
    
    def value(self, state):
        state = torch.from_numpy(state).float()
        _, value = self.forward(state)
        return value
    
    def update(self, rollouts):
        states, actions, log_probs, returns, advantages = rollouts
        mu, std = self.forward(states)
        dist = torch.distributions.Normal(mu, std)
        log_probs_old = dist.log_prob(actions)

        for _ in range(10):
            mu, std = self.forward(states)
            dist = torch.distributions.Normal(mu, std)
            log_probs_new = dist.log_prob(actions)
            ratio = (log_probs_new - log_probs_old).exp()
            surr1 = ratio * advantages
            surr2 = torch.clamp(ratio, 1.0 - 0.2, 1.0 + 0.2) * advantages
            actor_loss = -torch.min(surr1, surr2).mean()
            critic_loss = nn.functional.mse_loss(self.value(states), returns)
            loss = actor_loss + 0.5 * critic_loss
            self.optimizer.zero_grad()
            loss.backward()
            self.optimizer.step()

class DroneEnv(gym.Env):
    def __init__(self):
        self.view_width = 500
        self.view_height = 500
        self.balloon_radius = 10
        self.drone_radius = 10
        self.action_space = gym.spaces.Box(low=np.array([0.0, 0.0]), high=np.array([1.0, 1.0]), dtype=np.float32)
        self.observation_space = gym.spaces.Box(low=np.array([0, 0]), high=np.array([self.view_width, self.view_height]), dtype=np.float32)
        self.drone_pos = np.array([self.view_width/2, self.view_height/2])
        self.balloon_pos = np.array([0, 0])
        self.steps = 0
        self.max_steps = 1000
        
    def reset(self):
        self.drone_pos = np.array([self.view_width/2, self.view_height/2])
        self.balloon_pos = np.array([np.random.randint(self.view_width), np.random.randint(self.view_height)])
        self.steps = 0
        return self.drone_pos
    

import pygame

def draw_balloons(screen, balloons):
    for pos in balloons:
        pygame.draw.circle(screen, (255, 0, 0), (int(pos[0]), int(pos[1])), 10)

def draw_drone(screen, drone_pos):
    pygame.draw.circle(screen, (0, 255, 0), (int(drone_pos[0]), int(drone_pos[1])), 10)

def run():
    env = DroneEnv()
    actor_critic = ActorCritic()
    state = env.reset()

    pygame.init()
    screen = pygame.display.set_mode((env.view_width, env.view_height))
    pygame.display.set_caption("Drone Environment")

    running = True
    while running:
        action, _ = actor_critic.choose_action(state)
        action = np.array([max(action[0], 0), max(action[1], 0)])  # Make sure actions are not negative
        next_state, reward, done, info = env.step(action)

        screen.fill((255, 255, 255))
        draw_balloons(screen, env.balloons)
        draw_drone(screen, env.drone_pos)
        pygame.display.flip()

        state = next_state
        if done:
            state = env.reset()
