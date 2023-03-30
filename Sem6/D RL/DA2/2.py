import random

# Define the environment as a grid world
# where the agent can move up, down, left, or right
# to reach a goal state while avoiding obstacles
env = [
    [-1, -1, -1, -1, -1],
    [-1, -1, -1, -1, -1],
    [-1, -1, -1, -1, -1],
    [-1, -1, -1, -1, -1],
    [-1, -1, -1, -1, 10]
]

# Define the size of the environment
n_states = 25
n_actions = 4

# Define the Q-table
Q = [[0 for _ in range(n_actions)] for _ in range(n_states)]

# Set the hyperparameters
learning_rate = 0.1
discount_factor = 0.9
epsilon = 0.1
n_episodes = 1000

# Define the epsilon-greedy policy
def epsilon_greedy(state):
    if random.random() < epsilon:
        # Choose a random action
        action = random.randint(0, n_actions - 1)
    else:
        # Choose the best action according to Q-value
        action = Q[state].index(max(Q[state]))
    return action

# Loop over episodes
for episode in range(n_episodes):
    # Reset the environment to the starting state
    state = 0
    while state != n_states - 1:
        # Choose an action using the epsilon-greedy policy
        action = epsilon_greedy(state)
        # Take the chosen action and observe the next state and reward
        next_state = action
        reward = env[state][action]
        # Update the Q-value of the current state and action
        Q[state][action] += learning_rate * (reward + discount_factor * max(Q[next_state]) - Q[state][action])
        # Move to the next state
        state = next_state

    # Check if the algorithm has converged
    if episode % 100 == 0:
        max_delta = 0
        for i in range(n_states):
            for j in range(n_actions):
                q_old = Q[i][j]
                Q[i][j] += learning_rate * (reward + discount_factor * max(Q[next_state]) - Q[i][j])
                delta = abs(q_old - Q[i][j])
                if delta > max_delta:
                    max_delta = delta
        if max_delta < 0.0001:
            break

# Print the learned Q-table
print(Q)
