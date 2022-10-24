# Islāmic Text Copier
# Nāṣir ʿAṭif

# arabic font used is Janna LT Bold

from tkinter import *
from tkinter import messagebox
import os
import requests
import socket
import webbrowser
import pyglet
import keyboard
import ctypes
from ctypes import windll
import pyperclip

# set itc to be dpi aware and add a custom font

ctypes.windll.shcore.SetProcessDpiAwareness(1)
pyglet.font.add_file("resources/nunito.ttf")

# init window

root = Tk()

winW = 620 # width of the window
winH = 320 # height of the window

scrW = root.winfo_screenwidth()
scrH = root.winfo_screenheight()

winX = (scrW / 2) - (winW / 2)
winY = (scrH / 2) - (winH / 2)

bg = "#240f4a"
hoverbg = "#1882ea"
regfont = "Nunito Regular"

root.iconbitmap("resources/icon.ico")
root.attributes("-topmost", True)

root.title("Islāmic Text Copier")
root.configure(bg=bg)
root.resizable(0,0)
root.geometry(f"{winW}x{winH}+{int(winX)}+{int(winY)}")

# the entire point of this program

def btn1():
    pyperclip.copy("ﷺ")
    copyinf.config(text="Just copied: ﷺ")

keyboard.add_hotkey("alt+1", lambda : pyperclip.copy("ﷺ"))
keyboard.add_hotkey("alt+1", lambda : copyinf.config(text="Just copied: ﷺ"))

def btn2():
    pyperclip.copy("ﷻ")
    copyinf.config(text="Just copied: ﷻ")

keyboard.add_hotkey("alt+2", lambda : pyperclip.copy("ﷻ"))
keyboard.add_hotkey("alt+2", lambda : copyinf.config(text="Just copied: ﷻ"))

def btn3():
    pyperclip.copy("سبحانه و تعالى")
    copyinf.config(text="Just copied: سبحانه و تعالى")

keyboard.add_hotkey("alt+3", lambda : pyperclip.copy("سبحانه و تعالى"))
keyboard.add_hotkey("alt+3", lambda : copyinf.config(text="Just copied: سبحانه و تعالى"))

def btn4():
    pyperclip.copy("عز و جل")
    copyinf.config(text="Just copied: عز و جل")

keyboard.add_hotkey("alt+4", lambda : pyperclip.copy("عز و جل"))
keyboard.add_hotkey("alt+4", lambda : copyinf.config(text="Just copied: عز و جل"))

def btn5():
    pyperclip.copy("رضي الله عنه")
    copyinf.config(text="Just copied: رضي الله عنه")

keyboard.add_hotkey("alt+5", lambda : pyperclip.copy("رضي الله عنه"))
keyboard.add_hotkey("alt+5", lambda : copyinf.config(text="Just copied: رضي الله عنه"))

def btn6():
    pyperclip.copy("رضي الله عنها")
    copyinf.config(text="Just copied: رضي الله عنها")

keyboard.add_hotkey("alt+6", lambda : pyperclip.copy("رضي الله عنها"))
keyboard.add_hotkey("alt+6", lambda : copyinf.config(text="Just copied: رضي الله عنها"))

def btn7():
    pyperclip.copy("رحمه الله")
    copyinf.config(text="Just copied: رحمه الله")

keyboard.add_hotkey("alt+7", lambda : pyperclip.copy("رحمه الله"))
keyboard.add_hotkey("alt+7", lambda : copyinf.config(text="Just copied: رحمه الله"))

def btn8():
    pyperclip.copy("حفظه الله")
    copyinf.config(text="Just copied: حفظه الله")

keyboard.add_hotkey("alt+8", lambda : pyperclip.copy("حفظه الله"))
keyboard.add_hotkey("alt+8", lambda : copyinf.config(text="Just copied: حفظه الله"))

def btn9():
    pyperclip.copy("عليه السلام")
    copyinf.config(text="Just copied: عليه السلام")

keyboard.add_hotkey("alt+9", lambda : pyperclip.copy("عليه السلام"))
keyboard.add_hotkey("alt+9", lambda : copyinf.config(text="Just copied: عليه السلام"))

def btn10():
    pyperclip.copy("ٱلْحَمْدُ لِلَّٰهِ")
    copyinf.config(text="Just copied: ٱلْحَمْدُ لِلَّٰهِ")

keyboard.add_hotkey("alt+0", lambda : pyperclip.copy("ٱلْحَمْدُ لِلَّٰهِ"))
keyboard.add_hotkey("alt+0", lambda : copyinf.config(text="Just copied: ٱلْحَمْدُ لِلَّٰهِ"))

def btn11():
    pyperclip.copy("جَزَاكَ ٱللَّٰهُ خَيْرًا")
    copyinf.config(text="Just copied: جَزَاكَ ٱللَّٰهُ خَيْرًا")

keyboard.add_hotkey("alt+-", lambda : pyperclip.copy("جَزَاكَ ٱللَّٰهُ خَيْرًا"))
keyboard.add_hotkey("alt+-", lambda : copyinf.config(text="Just copied: جَزَاكَ ٱللَّٰهُ خَيْرًا"))

# other functions

def hoverh(event):
    htip["bg"] = hoverbg

def hoverhl(event):
    htip["bg"] = "#1f0c42"

def hmsg():
    os.startfile("ITC_Documentation.pdf", "open")
    root.wm_state("iconic")

homeurllink = "http://nasiratif.net/islamic-text-copier/"

def homeurl(url):
    webbrowser.open_new_tab(homeurllink)

def hover9l(event):
    btn9["bg"] = bg

def hover1(event):
    btn1["bg"] = hoverbg

def hover1l(event):
    btn1["bg"] = bg

def hover2(event):
    btn2["bg"] = hoverbg

def hover2l(event):
    btn2["bg"] = bg

def hover3(event):
    btn3["bg"] = hoverbg

def hover3l(event):
    btn3["bg"] = bg

def hover4(event):
    btn4["bg"] = hoverbg

def hover4l(event):
    btn4["bg"] = bg

def hover5(event):
    btn5["bg"] = hoverbg

def hover5l(event):
    btn5["bg"] = bg

def hover6(event):
    btn6["bg"] = hoverbg

def hover6l(event):
    btn6["bg"] = bg

def hover7(event):
    btn7["bg"] = hoverbg

def hover7l(event):
    btn7["bg"] = bg

def hover8(event):
    btn8["bg"] = hoverbg

def hover8l(event):
    btn8["bg"] = bg

def hover9(event):
    btn9["bg"] = hoverbg

def hover9l(event):
    btn9["bg"] = bg

def hover10(event):
    btn10["bg"] = hoverbg

def hover10l(event):
    btn10["bg"] = bg

def hover11(event):
    btn11["bg"] = hoverbg

def hover11l(event):
    btn11["bg"] = bg

def hoverc(event):
    copyrighttxt["fg"] = "gray"

def hovercl(event):
    copyrighttxt["fg"] = "white"

# gui

copyinf = Label(text="Just copied: None", font=(regfont, 9), bg=bg, fg="white")
copyinf.pack(side="bottom", pady=7)

btn1_img = PhotoImage(file="resources/1.png")
btn2_img = PhotoImage(file="resources/2.png")
btn3_img = PhotoImage(file="resources/3.png")
btn4_img = PhotoImage(file="resources/4.png")
btn5_img = PhotoImage(file="resources/5.png")
btn6_img = PhotoImage(file="resources/6.png")
btn7_img = PhotoImage(file="resources/7.png")
btn8_img = PhotoImage(file="resources/8.png")
btn9_img = PhotoImage(file="resources/9.png")
btn10_img = PhotoImage(file="resources/10.png")
btn11_img = PhotoImage(file="resources/11.png")

copyrighttxt = Label(text="© Nāṣir ʿAṭif\nv2.1", bg=bg, fg="white", font=(regfont, 8))
copyrighttxt.place(x=8, y=8)
copyrighttxt.bind("<Enter>", hoverc)
copyrighttxt.bind("<Leave>", hovercl)
copyrighttxt.bind("<Button-1>", lambda e:homeurl(homeurl))

htip = Button(text="Documentation", command=hmsg, font=(regfont, 8), bg="#1f0c42", activebackground="#1f0c42", fg="white", activeforeground="white", borderwidth=0)
htip.place(relx=0.5, rely=0.12, anchor=CENTER)
htip.bind("<Enter>", hoverh)
htip.bind("<Leave>", hoverhl)

btn1 = Button(root, command=btn1, image=btn1_img, bg=bg, activebackground=bg, borderwidth=0)
btn1.place(relx=0.15, rely=0.24)
btn1.bind("<Enter>", hover1)
btn1.bind("<Leave>", hover1l)

btn2 = Button(root, command=btn2, image=btn2_img, bg=bg, activebackground=bg, borderwidth=0)
btn2.place(relx=0.25, rely=0.26)
btn2.bind("<Enter>", hover2)
btn2.bind("<Leave>", hover2l)

btn3 = Button(root, command=btn3, image=btn3_img, bg=bg, activebackground=bg, borderwidth=0)
btn3.place(relx=0.33, rely=0.27)
btn3.bind("<Enter>", hover3)
btn3.bind("<Leave>", hover3l)

btn4 = Button(root, command=btn4, image=btn4_img, bg=bg, activebackground=bg, borderwidth=0)
btn4.place(relx=0.55, rely=0.27)
btn4.bind("<Enter>", hover4)
btn4.bind("<Leave>", hover4l)

btn5 = Button(root, command=btn5, image=btn5_img, bg=bg, activebackground=bg, borderwidth=0)
btn5.place(relx=0.68, rely=0.27)
btn5.bind("<Enter>", hover5)
btn5.bind("<Leave>", hover5l)

btn6 = Button(root, command=btn6, image=btn6_img, bg=bg, activebackground=bg, borderwidth=0)
btn6.place(relx=0.15, rely=0.45)
btn6.bind("<Enter>", hover6)
btn6.bind("<Leave>", hover6l)

btn7 = Button(root, command=btn7, image=btn7_img, bg=bg, activebackground=bg, borderwidth=0)
btn7.place(relx=0.35, rely=0.45)
btn7.bind("<Enter>", hover7)
btn7.bind("<Leave>", hover7l)

btn8 = Button(root, command=btn8, image=btn8_img, bg=bg, activebackground=bg, borderwidth=0)
btn8.place(relx=0.50, rely=0.45)
btn8.bind("<Enter>", hover8)
btn8.bind("<Leave>", hover8l)

btn9 = Button(root, command=btn9, image=btn9_img, bg=bg, activebackground=bg, borderwidth=0)
btn9.place(relx=0.66, rely=0.45)
btn9.bind("<Enter>", hover9)
btn9.bind("<Leave>", hover9l)

btn10 = Button(root, command=btn10, image=btn10_img, bg=bg, activebackground=bg, borderwidth=0)
btn10.place(relx=0.15, rely=0.60)
btn10.bind("<Enter>", hover10)
btn10.bind("<Leave>", hover10l)

btn11 = Button(root, command=btn11, image=btn11_img, bg=bg, activebackground=bg, borderwidth=0)
btn11.place(relx=0.30, rely=0.60)
btn11.bind("<Enter>", hover11)
btn11.bind("<Leave>", hover11l)

# check if the system is connected to the internet before checking for updates
# otherwise itc would crash

def testnet():
    try:
        socket.create_connection(("nasiratif.net", 443))
        return True
    except OSError:
        return False

isconnected = testnet()

# check for updates

 # set current version of itc in this variable:
itcversion = 13

if isconnected == True:
    request = requests.get("http://nasiratif.net/dl/version.txt")
    open("version.txt", "wb").write(request.content)

    if os.path.isfile(r"version.txt"):
        f=open(r"version.txt", "r")
        fileversion = f.read() .replace("\n", "").strip()
        if float(fileversion) > float(itcversion):
            f.close()
            updatemsg = messagebox.askquestion(title="Update Available", message="Alḥamdulillāh, an update is available. Go to the home page to download it?")
            if updatemsg == "yes":
                webbrowser.open("http://nasiratif.net/islamic-text-copier/")
                root.destroy()

root.mainloop()