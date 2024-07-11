from twilio.rest import Client

account_sid = 'AC1006684c2e66fc21dca5d41a1acb1ed1'
auth_token = '42aa5a45a3c9b9be10ac92d3584a9eeb'
client = Client(account_sid, auth_token)

message = client.messages.create(
  from_='+17603096983',
  body='hi',
  to='+201129860337'
)

print(message.sid)