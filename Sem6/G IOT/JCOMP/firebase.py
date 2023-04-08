import firebase_admin
from firebase_admin import credentials
from firebase_admin import firestore
import datetime
from google.api_core.datetime_helpers import DatetimeWithNanoseconds
class FIREBASE:
    def __init__(self):
        self.cred = credentials.Certificate('firebase_pvt_key.json')
        self.app = firebase_admin.initialize_app(self.cred)
        self.db = firestore.client()
        self.name_to_id={
            'Subhranshu':'5dMQckm0YnOHbNuLiFkyB8XP5DH3',
        }
    def compareDates(self,date1,date2):
        if date1.year==date2.year and date1.month==date2.month and date1.day==date2.day:
            return True
        return False
    
    def postAttendance(self,id):
        student_ref = self.db.collection(u'Students').document(id)
        doc = student_ref.get()
        if doc.exists:
            data=doc.to_dict()['Attendance']
            now=DatetimeWithNanoseconds.now()
            now = now.replace(day=now.day-1 ,hour=18, minute=30, second=0, tzinfo=datetime.timezone.utc)
            now._nanosecond=0
            if self.compareDates(data[-1],now):
                print(f'[-]Attendance already updated for {id}')
                return
            data.append(now)
            student_ref.update({
                u'Attendance': data
            })
            print(f'[!]Attendance updated')
        else:
            print(u'[-]No such document!')
        
    
    def update_data(self,detected_faces):
        for name in detected_faces:
            try:
                id=self.name_to_id[name]
                self.postAttendance(id)
            except:
                print(f'[-]No such student {name}')
        