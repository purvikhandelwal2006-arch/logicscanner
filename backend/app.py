from flask import Flask , request
import os
app = Flask(__name__)
@app.route("/scan",methods=["POST"])
def scan():
    code=request.json["code"]
    with open("input.txt","w") as f:
        f.write(code)
    os.system("logic.exe input.txt > output.txt")
    with open("output.txt") as f:
        result=f.read()
    return result 
app.run()