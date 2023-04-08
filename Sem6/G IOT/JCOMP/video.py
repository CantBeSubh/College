import cv2
from facerec import FACEREC
from firebase import FIREBASE
class VIDEO:
    def __init__(self,index=0):
        self.sfr=FACEREC()
        self.fb=FIREBASE()
        self.sfr.load_encoding_images("images/")
        self.detected_faces=set()
        try:
            self.cap=cv2.VideoCapture(index)
        except:
            print("[-]Invalid camera index <using default camera>")
            self.cap=cv2.VideoCapture(0)
    
    def clean_name(self,name):
        return '' .join((x for x in name if not x.isdigit()))
    
    def print_detected(self):
        print("[+]Detected Faces: ", ", ".join(self.detected_faces))

    def update_data(self):
        self.fb.update_data(self.detected_faces)
                
    def detect_faces(self):
        while(True):
            ret,frame=self.cap.read()
            face_locations,face_names=self.sfr.detect_known_faces(frame)
            for face_loc,name in zip(face_locations,face_names):
                clean_name=self.clean_name(name)
                y1,x2,y2,x1=face_loc[0],face_loc[1],face_loc[2],face_loc[3]
                if clean_name in self.detected_faces:
                    cv2.putText(frame,clean_name,(x1,y1-10),cv2.FONT_HERSHEY_DUPLEX,1,(0,200,0),2)
                    cv2.rectangle(frame,(x1,y1),(x2,y2),(0,200,0),4)
                else:
                    cv2.putText(frame,clean_name,(x1,y1-10),cv2.FONT_HERSHEY_DUPLEX,1,(0,0,200),2)
                    cv2.rectangle(frame,(x1,y1),(x2,y2),(0,0,200),4)
                if name!="Unknown":
                    self.detected_faces.add(clean_name)
            cv2.imshow("Frame",frame)
            if cv2.waitKey(1) & 0xFF == ord('q'):
                break
        self.print_detected()
        self.update_data()
        self.cap.release()
        cv2.destroyAllWindows()