import firebase_admin
from firebase_admin import credentials
from firebase_admin import firestore
import datetime
from google.api_core.datetime_helpers import DatetimeWithNanoseconds
import pytz

# Use a service account.
cred = credentials.Certificate('firebase_pvt_key.json')

app = firebase_admin.initialize_app(cred)

db = firestore.client()

student_ref = db.collection(u'Students').document(u'5dMQckm0YnOHbNuLiFkyB8XP5DH3')
doc = student_ref.get()
if doc.exists:
    data=doc.to_dict()['Attendance']
    now=DatetimeWithNanoseconds.now()
    now = now.replace(day=now.day-1 ,hour=18, minute=30, second=0, tzinfo=datetime.timezone.utc)
    now._nanosecond=0
    data.append(now)
    student_ref.update({
        u'Attendance': data
    })

    # dates=datetime.fromtimestamp(data.timestamp())
    # dates= map(lambda x: datetime.fromtimestamp(x.timestamp()), data)
    # print(list(dates))
    print(f'Document data: {data}')
else:
    print(u'No such document!')

# class FIREBASE:
#     def __init__(self):
#         pass
#     def postAttendance(self,id):
#         db = firestore.client()
#         users_ref = db.collection(u'Students')
#         docs = users_ref.stream()
#         for doc in docs:
#             if doc.id == id:
#                 doc_ref = db.collection(u'Students').document(id)
#                 doc_ref.update({
#                     u'Attendance': firestore.Increment(1)
#                 })
#                 print("Attendance Updated")
#                 break
#             else:
#                 print("Student not found")
#                 break