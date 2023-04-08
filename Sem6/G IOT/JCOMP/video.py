import cv2
from simple_facerec import SimpleFacerec
from simple_firebase import FIREBASE

# Encode faces from a folder
sfr = SimpleFacerec()
sfr.load_encoding_images("images/")

# Load Camera
cap = cv2.VideoCapture(0)
detected_faces = set()

while True:
    ret, frame = cap.read()

    # Detect Faces
    face_locations, face_names = sfr.detect_known_faces(frame)
    for face_loc, name in zip(face_locations, face_names):
        if name!="Unknown":
            clean_name = '' .join((x for x in name if not x.isdigit()))
            detected_faces.add(clean_name)
            # print("Detected Faces: ", ", ".join(detected_faces))
        y1, x2, y2, x1 = face_loc[0], face_loc[1], face_loc[2], face_loc[3]
        if name in detected_faces:
            cv2.putText(frame, name,(x1, y1 - 10), cv2.FONT_HERSHEY_DUPLEX, 1, (0, 200, 0), 2)
            cv2.rectangle(frame, (x1, y1), (x2, y2), (0, 200, 0), 4)
        else:
            cv2.putText(frame, name,(x1, y1 - 10), cv2.FONT_HERSHEY_DUPLEX, 1, (0, 0, 200), 2)
            cv2.rectangle(frame, (x1, y1), (x2, y2), (0, 0, 200), 4)

    cv2.imshow("Frame", frame)

    # key = cv2.waitKey(1)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

print(detected_faces)
FIREBASE().update_data(detected_faces)
cap.release()
cv2.destroyAllWindows()