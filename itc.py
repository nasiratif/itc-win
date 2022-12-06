# Islāmic Text Copier
# Nāṣir ʿAṭif

# arabic font used is Segoe UI

from tkinter import *
from hdpitkinter import HdpiTk
from tkinter import messagebox
from os import startfile, path
from requests import get
from socket import create_connection
import webbrowser
from pyglet import font
from keyboard import add_hotkey
from ctypes import windll
from pyperclip import *

# init window

font.add_file("resources/calibri.ttf")

root = HdpiTk()

winW = 620 # width of the window
winH = 320 # height of the window

scrW = windll.user32.GetSystemMetrics(0)
scrH = windll.user32.GetSystemMetrics(1)

winX = (scrW / 2) - (winW / 2)
winY = (scrH / 2) - (winH / 2)

bg = "#1b1c27"
hoverbg = "#393c4f"
htipbg = "#191a24"
regfont = "Calibri"

root.iconbitmap("resources/icon.ico")
root.attributes("-topmost", True)

root.title("Islāmic Text Copier")
root.configure(bg=bg)
root.resizable(0,0)
root.geometry(f"{winW}x{winH}+{int(winX)}+{int(winY)}")

# the entire point of this program

def btn1():
    copy("ﷺ")
    copyinf.config(text="Just copied: ﷺ")

add_hotkey("alt+1", lambda : copy("ﷺ"))
add_hotkey("alt+1", lambda : copyinf.config(text="Just copied: ﷺ"))

def btn2():
    copy("ﷻ")
    copyinf.config(text="Just copied: ﷻ")

add_hotkey("alt+2", lambda : copy("ﷻ"))
add_hotkey("alt+2", lambda : copyinf.config(text="Just copied: ﷻ"))

def btn3():
    copy("سبحانه و تعالى")
    copyinf.config(text="Just copied: سبحانه و تعالى")

add_hotkey("alt+3", lambda : copy("سبحانه و تعالى"))
add_hotkey("alt+3", lambda : copyinf.config(text="Just copied: سبحانه و تعالى"))

def btn4():
    copy("عز و جل")
    copyinf.config(text="Just copied: عز و جل")

add_hotkey("alt+4", lambda : copy("عز و جل"))
add_hotkey("alt+4", lambda : copyinf.config(text="Just copied: عز و جل"))

def btn5():
    copy("رضي الله عنه")
    copyinf.config(text="Just copied: رضي الله عنه")

add_hotkey("alt+5", lambda : copy("رضي الله عنه"))
add_hotkey("alt+5", lambda : copyinf.config(text="Just copied: رضي الله عنه"))

def btn6():
    copy("رضي الله عنها")
    copyinf.config(text="Just copied: رضي الله عنها")

add_hotkey("alt+6", lambda : copy("رضي الله عنها"))
add_hotkey("alt+6", lambda : copyinf.config(text="Just copied: رضي الله عنها"))

def btn7():
    copy("رحمه الله")
    copyinf.config(text="Just copied: رحمه الله")

add_hotkey("alt+7", lambda : copy("رحمه الله"))
add_hotkey("alt+7", lambda : copyinf.config(text="Just copied: رحمه الله"))

def btn8():
    copy("حفظه الله")
    copyinf.config(text="Just copied: حفظه الله")

add_hotkey("alt+8", lambda : copy("حفظه الله"))
add_hotkey("alt+8", lambda : copyinf.config(text="Just copied: حفظه الله"))

def btn9():
    copy("عليه السلام")
    copyinf.config(text="Just copied: عليه السلام")

add_hotkey("alt+9", lambda : copy("عليه السلام"))
add_hotkey("alt+9", lambda : copyinf.config(text="Just copied: عليه السلام"))

def btn10():
    copy("الحمد لله")
    copyinf.config(text="Just copied: الحمد لله")

add_hotkey("alt+0", lambda : copy("الحمد لله"))
add_hotkey("alt+0", lambda : copyinf.config(text="Just copied: الحمد لله"))

def btn11():
    copy("جزاك الله خيرا")
    copyinf.config(text="Just copied: جزاك الله خيرا")

add_hotkey("alt+-", lambda : copy("جزاك الله خيرا"))
add_hotkey("alt+-", lambda : copyinf.config(text="Just copied: جزاك الله خيرا"))

def btn12():
    copy("بارك الله فيك")
    copyinf.config(text="Just copied: بارك الله فيك")

add_hotkey("alt+=", lambda : copy("بارك الله فيك"))
add_hotkey("alt+=", lambda : copyinf.config(text="Just copied: بارك الله فيك"))

def btn13():
    copy("السلام عليكم")
    copyinf.config(text="Just copied: السلام عليكم")

add_hotkey("alt+[", lambda : copy("بارك الله فيك"))
add_hotkey("alt+[", lambda : copyinf.config(text="Just copied: السلام عليكم"))

# other functions

def hoverh(event):
    htip["bg"] = hoverbg

def hoverhl(event):
    htip["bg"] = htipbg

def hmsg():
    startfile("ITC_Documentation.pdf", "open")
    root.wm_state("iconic")

homeurllink = "http://nasiratif.net/islamic-text-copier/"

def homeurl(url):
    webbrowser.open_new_tab(homeurllink)

def hover9l(event):
    btn9["bg"] = bg

def hover1(event):
    btn1["bg"] = hoverbg
    copyinf.config(text="Sallá Allāhu ʿAlayhī wa as-Salam (ALT + 1)")

def hover1l(event):
    btn1["bg"] = bg
    copyinf.config(text=copyinf_d)

def hover2(event):
    btn2["bg"] = hoverbg
    copyinf.config(text="Jalla Jalāluhu (ALT + 2)")

def hover2l(event):
    btn2["bg"] = bg
    copyinf.config(text=copyinf_d)

def hover3(event):
    btn3["bg"] = hoverbg
    copyinf.config(text="Subḥānahu wa Taʾālá (ALT + 3)")

def hover3l(event):
    btn3["bg"] = bg
    copyinf.config(text=copyinf_d)

def hover4(event):
    btn4["bg"] = hoverbg
    copyinf.config(text="ʿAzza wa Jal (ALT + 4)")

def hover4l(event):
    btn4["bg"] = bg
    copyinf.config(text=copyinf_d)

def hover5(event):
    btn5["bg"] = hoverbg
    copyinf.config(text="Raḍī Allāhu ʿAnhu (ALT + 5)")

def hover5l(event):
    btn5["bg"] = bg
    copyinf.config(text=copyinf_d)

def hover6(event):
    btn6["bg"] = hoverbg
    copyinf.config(text="Raḍī Allāhu ʿAnhā (ALT + 6)")

def hover6l(event):
    btn6["bg"] = bg
    copyinf.config(text=copyinf_d)

def hover7(event):
    btn7["bg"] = hoverbg
    copyinf.config(text="Raḥimahullāh (ALT + 7)")

def hover7l(event):
    btn7["bg"] = bg
    copyinf.config(text=copyinf_d)

def hover8(event):
    btn8["bg"] = hoverbg
    copyinf.config(text="Ḥafiẓahullāh (ALT + 8)")

def hover8l(event):
    btn8["bg"] = bg
    copyinf.config(text=copyinf_d)

def hover9(event):
    btn9["bg"] = hoverbg
    copyinf.config(text="ʿAlayhī as-Salām (ALT + 9)")

def hover9l(event):
    btn9["bg"] = bg
    copyinf.config(text=copyinf_d)

def hover10(event):
    btn10["bg"] = hoverbg
    copyinf.config(text="Alḥamdulillāh (ALT + 0)")

def hover10l(event):
    btn10["bg"] = bg
    copyinf.config(text=copyinf_d)

def hover11(event):
    btn11["bg"] = hoverbg
    copyinf.config(text="Jazāk Allāhu Khairan (ALT + - (Dash Symbol) )")

def hover11l(event):
    btn11["bg"] = bg
    copyinf.config(text=copyinf_d)

def hover12(event):
    btn12["bg"] = hoverbg
    copyinf.config(text="Bārik Allāhu Fīk (ALT + = (Equal Symbol) )")

def hover12l(event):
    btn12["bg"] = bg
    copyinf.config(text=copyinf_d)

def hover13(event):
    btn13["bg"] = hoverbg
    copyinf.config(text="As Salāmu ‘Alaikum (ALT + [ (Left Square Bracket Symbol) )")

def hover13l(event):
    btn13["bg"] = bg
    copyinf.config(text=copyinf_d)

def hoverc(event):
    copyrighttxt["fg"] = "gray"

def hovercl(event):
    copyrighttxt["fg"] = "white"

# gui

copyinf_d = "Hover over a text to see it's meaning in English"
copyinf = Label(text=copyinf_d, font=(regfont, 13), bg=bg, fg="white")
copyinf.pack(side="bottom", pady=15)

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
btn12_img = PhotoImage(file="resources/12.png")
btn13_img = PhotoImage(file="resources/13.png")

copyrighttxt = Label(text="© Nāṣir ʿAṭif\nv2.3.2", bg=bg, fg="white", font=(regfont, 13))
copyrighttxt.place(x=8, y=8)
copyrighttxt.bind("<Enter>", hoverc)
copyrighttxt.bind("<Leave>", hovercl)
copyrighttxt.bind("<Button-1>", lambda e:homeurl(homeurl))

htip = Button(text="Documentation", command=hmsg, font=(regfont, 13), bg=htipbg, activebackground=htipbg, fg="white", activeforeground="white", borderwidth=0)
htip.place(relx=0.5, rely=0.12, anchor=CENTER)
htip.bind("<Enter>", hoverh)
htip.bind("<Leave>", hoverhl)

btn1 = Button(root, command=btn1, image=btn1_img, bg=bg, activebackground=bg, borderwidth=0)
btn1.place(relx=0.13, rely=0.24)
btn1.bind("<Enter>", hover1)
btn1.bind("<Leave>", hover1l)

btn2 = Button(root, command=btn2, image=btn2_img, bg=bg, activebackground=bg, borderwidth=0)
btn2.place(relx=0.24, rely=0.26)
btn2.bind("<Enter>", hover2)
btn2.bind("<Leave>", hover2l)

btn3 = Button(root, command=btn3, image=btn3_img, bg=bg, activebackground=bg, borderwidth=0)
btn3.place(relx=0.33, rely=0.29)
btn3.bind("<Enter>", hover3)
btn3.bind("<Leave>", hover3l)

btn4 = Button(root, command=btn4, image=btn4_img, bg=bg, activebackground=bg, borderwidth=0)
btn4.place(relx=0.54, rely=0.28)
btn4.bind("<Enter>", hover4)
btn4.bind("<Leave>", hover4l)

btn5 = Button(root, command=btn5, image=btn5_img, bg=bg, activebackground=bg, borderwidth=0)
btn5.place(relx=0.67, rely=0.27)
btn5.bind("<Enter>", hover5)
btn5.bind("<Leave>", hover5l)

btn6 = Button(root, command=btn6, image=btn6_img, bg=bg, activebackground=bg, borderwidth=0)
btn6.place(relx=0.14, rely=0.45)
btn6.bind("<Enter>", hover6)
btn6.bind("<Leave>", hover6l)

btn7 = Button(root, command=btn7, image=btn7_img, bg=bg, activebackground=bg, borderwidth=0)
btn7.place(relx=0.34, rely=0.45)
btn7.bind("<Enter>", hover7)
btn7.bind("<Leave>", hover7l)

btn8 = Button(root, command=btn8, image=btn8_img, bg=bg, activebackground=bg, borderwidth=0)
btn8.place(relx=0.49, rely=0.45)
btn8.bind("<Enter>", hover8)
btn8.bind("<Leave>", hover8l)

btn9 = Button(root, command=btn9, image=btn9_img, bg=bg, activebackground=bg, borderwidth=0)
btn9.place(relx=0.65, rely=0.46)
btn9.bind("<Enter>", hover9)
btn9.bind("<Leave>", hover9l)

btn10 = Button(root, command=btn10, image=btn10_img, bg=bg, activebackground=bg, borderwidth=0)
btn10.place(relx=0.14, rely=0.62)
btn10.bind("<Enter>", hover10)
btn10.bind("<Leave>", hover10l)

btn11 = Button(root, command=btn11, image=btn11_img, bg=bg, activebackground=bg, borderwidth=0)
btn11.place(relx=0.29, rely=0.62)
btn11.bind("<Enter>", hover11)
btn11.bind("<Leave>", hover11l)

btn12 = Button(root, command=btn12, image=btn12_img, bg=bg, activebackground=bg, borderwidth=0)
btn12.place(relx=0.49, rely=0.62)
btn12.bind("<Enter>", hover12)
btn12.bind("<Leave>", hover12l)

btn13 = Button(root, command=btn13, image=btn13_img, bg=bg, activebackground=bg, borderwidth=0)
btn13.place(relx=0.69, rely=0.63)
btn13.bind("<Enter>", hover13)
btn13.bind("<Leave>", hover13l)

# check if the system is connected to the internet before checking for updates
# otherwise itc would crash

def testnet():
    try:
        create_connection(("nasiratif.net", 443))
        return True
    except OSError:
        return False

isconnected = testnet()

# check for updates

 # set current version of itc in this variable:
itcversion = 17

if isconnected == True:
    request = get("http://nasiratif.net/dl/version.txt")
    open("version.txt", "wb").write(request.content)

    if path.isfile(r"version.txt"):
        f=open(r"version.txt", "r")
        fileversion = f.read() .replace("\n", "").strip()
        if float(fileversion) > float(itcversion):
            f.close()
            updatemsg = messagebox.askquestion(title="Update Available", message="Alḥamdulillāh, an update is available. Go to the home page to download it?")
            if updatemsg == "yes":
                webbrowser.open("http://nasiratif.net/islamic-text-copier/")
                root.destroy()

root.mainloop()