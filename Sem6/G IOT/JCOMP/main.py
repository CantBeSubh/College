from video import VIDEO
import sys

if __name__ == '__main__':
    print("WELCOME")
    print("[+]Initializing...")
    try:
        print("[+]Using camera {}".format(sys.argv[1]))
        video = VIDEO(int(sys.argv[1]))
    except:
        print("[!]No argument passed <using default camera>")
        video = VIDEO(0)
    
    print("[+]Initialized")
    print("[!]Press 'q' to quit")
    video.detect_faces()
    print("[+]Exiting...")
    print("GOODBYE")
