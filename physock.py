import socket

physock = socket.socket()
nhost = socket.gethostname()
port = 1028

physock.bind((nhost,port))

physock.listen(5)

while True:
  c, addr = physock.accept() 
  print 'Got connection from', addr
  c.send('Already Connecting') 
  c.close()

