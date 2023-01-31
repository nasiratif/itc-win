# Islāmic Text Copier
# Nāṣir ʿAṭif

# arabic font used is Segoe UI

from tkinter import *
from PIL import ImageTk, Image
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

windll.shcore.SetProcessDpiAwareness(1)  # set DPI awareness

font.add_file("resources/calibri.ttf")

root = Tk()
print("Init window")

ppi = round(root.winfo_fpixels("1i"))
print("PPI is " + str(ppi))
dpiscale = ppi / 96
print("Calculated DPI scale is " + str(dpiscale))

winW = int(620 * dpiscale)  # width of the window
winH = int(320 * dpiscale)  # height of the window

scrW = windll.user32.GetSystemMetrics(0)
scrH = windll.user32.GetSystemMetrics(1)

winX = (scrW / 2) - (winW / 2)
winY = (scrH / 2) - (winH / 2)
root.geometry(f"{winW}x{winH}+{int(winX)}+{int(winY)}")
root.iconbitmap("resources/icon.ico")
root.attributes("-topmost", True)
root.title("Islāmic Text Copier")
root.resizable(0, 0)

bg = "#1b1c27"
hoverbg = "#393c4f"
docubtn_bg = "#191a24"
regfont = "Calibri"

root.configure(bg=bg)

# the entire point of this program


def btn1():
    copy("ﷺ")
    copyinf.config(text="Just copied: ﷺ")


add_hotkey("alt+1", lambda: copy("ﷺ"))
add_hotkey("alt+1", lambda: copyinf.config(text="Just copied: ﷺ"))


def btn2():
    copy("ﷻ")
    copyinf.config(text="Just copied: ﷻ")


add_hotkey("alt+2", lambda: copy("ﷻ"))
add_hotkey("alt+2", lambda: copyinf.config(text="Just copied: ﷻ"))


def btn3():
    copy("سبحانه و تعالى")
    copyinf.config(text="Just copied: سبحانه و تعالى")


add_hotkey("alt+3", lambda: copy("سبحانه و تعالى"))
add_hotkey("alt+3", lambda: copyinf.config(text="Just copied: سبحانه و تعالى"))


def btn4():
    copy("عز و جل")
    copyinf.config(text="Just copied: عز و جل")


add_hotkey("alt+4", lambda: copy("عز و جل"))
add_hotkey("alt+4", lambda: copyinf.config(text="Just copied: عز و جل"))


def btn5():
    copy("رضي الله عنه")
    copyinf.config(text="Just copied: رضي الله عنه")


add_hotkey("alt+5", lambda: copy("رضي الله عنه"))
add_hotkey("alt+5", lambda: copyinf.config(text="Just copied: رضي الله عنه"))


def btn6():
    copy("رضي الله عنها")
    copyinf.config(text="Just copied: رضي الله عنها")


add_hotkey("alt+6", lambda: copy("رضي الله عنها"))
add_hotkey("alt+6", lambda: copyinf.config(text="Just copied: رضي الله عنها"))


def btn7():
    copy("رحمه الله")
    copyinf.config(text="Just copied: رحمه الله")


add_hotkey("alt+7", lambda: copy("رحمه الله"))
add_hotkey("alt+7", lambda: copyinf.config(text="Just copied: رحمه الله"))


def btn8():
    copy("حفظه الله")
    copyinf.config(text="Just copied: حفظه الله")


add_hotkey("alt+8", lambda: copy("حفظه الله"))
add_hotkey("alt+8", lambda: copyinf.config(text="Just copied: حفظه الله"))


def btn9():
    copy("عليه السلام")
    copyinf.config(text="Just copied: عليه السلام")


add_hotkey("alt+9", lambda: copy("عليه السلام"))
add_hotkey("alt+9", lambda: copyinf.config(text="Just copied: عليه السلام"))


def btn10():
    copy("الحمد لله")
    copyinf.config(text="Just copied: الحمد لله")


add_hotkey("alt+0", lambda: copy("الحمد لله"))
add_hotkey("alt+0", lambda: copyinf.config(text="Just copied: الحمد لله"))


def btn11():
    copy("جزاك الله خيرا")
    copyinf.config(text="Just copied: جزاك الله خيرا")


add_hotkey("alt+-", lambda: copy("جزاك الله خيرا"))
add_hotkey("alt+-", lambda: copyinf.config(text="Just copied: جزاك الله خيرا"))


def btn12():
    copy("بارك الله فيك")
    copyinf.config(text="Just copied: بارك الله فيك")


add_hotkey("alt+=", lambda: copy("بارك الله فيك"))
add_hotkey("alt+=", lambda: copyinf.config(text="Just copied: بارك الله فيك"))


def btn13():
    copy("السلام عليكم")
    copyinf.config(text="Just copied: السلام عليكم")


add_hotkey("alt+[", lambda: copy("السلام عليكم"))
add_hotkey("alt+[", lambda: copyinf.config(text="Just copied: السلام عليكم"))


def btn14():
    copy("إن شاء الله")
    copyinf.config(text="Just copied: إن شاء الله")


add_hotkey("alt+]", lambda: copy("إن شاء الله"))
add_hotkey("alt+]", lambda: copyinf.config(text="Just copied: إن شاء الله"))

# other functions


def hoverh(event):
    docubtn["bg"] = hoverbg
    copyinf.config(text="View the documentation for Islāmic Text Copier.")


def hoverhl(event):
    docubtn["bg"] = docubtn_bg
    copyinf.config(text=copyinf_d)


def hmsg():
    startfile("ITC_Documentation.pdf", "open")
    root.wm_state("iconic")


homeurllink = "http://itc.nasiratif.net"


def homeurl(url):
    webbrowser.open_new_tab(homeurllink)


def hover9l(event):
    btn9["bg"] = bg


def hover1(event):
    btn1["bg"] = hoverbg
    copyinf.config(
        text="Sallá Allāhu ʿAlayhī wa as-Salam (May Allāh's praise & salutations be upon him) (ALT + 1)")


def hover1l(event):
    btn1["bg"] = bg
    copyinf.config(text=copyinf_d)


def hover2(event):
    btn2["bg"] = hoverbg
    copyinf.config(text="Jalla Jalāluhu (Exalted is His Majesty) (ALT + 2) ")


def hover2l(event):
    btn2["bg"] = bg
    copyinf.config(text=copyinf_d)


def hover3(event):
    btn3["bg"] = hoverbg
    copyinf.config(
        text="Subḥānahu wa Taʾālá (Glorious and Exalted is He) (ALT + 3)")


def hover3l(event):
    btn3["bg"] = bg
    copyinf.config(text=copyinf_d)


def hover4(event):
    btn4["bg"] = hoverbg
    copyinf.config(text="ʿAzza wa Jal (The Mighty and Majestic) (ALT + 4)")


def hover4l(event):
    btn4["bg"] = bg
    copyinf.config(text=copyinf_d)


def hover5(event):
    btn5["bg"] = hoverbg
    copyinf.config(
        text="Raḍī Allāhu ʿAnhu (May Allāh be pleased with him) (ALT + 5)")


def hover5l(event):
    btn5["bg"] = bg
    copyinf.config(text=copyinf_d)


def hover6(event):
    btn6["bg"] = hoverbg
    copyinf.config(
        text="Raḍī Allāhu ʿAnhā (May Allāh be pleased with her) (ALT + 6)")


def hover6l(event):
    btn6["bg"] = bg
    copyinf.config(text=copyinf_d)


def hover7(event):
    btn7["bg"] = hoverbg
    copyinf.config(text="Raḥimahullāh (May Allah have mercy on him) (ALT + 7)")


def hover7l(event):
    btn7["bg"] = bg
    copyinf.config(text=copyinf_d)


def hover8(event):
    btn8["bg"] = hoverbg
    copyinf.config(text="Ḥafiẓahullāh (May Allah have preserve him) (ALT + 8)")


def hover8l(event):
    btn8["bg"] = bg
    copyinf.config(text=copyinf_d)


def hover9(event):
    btn9["bg"] = hoverbg
    copyinf.config(text="ʿAlayhī as-Salām (Peace be upon him) (ALT + 9)")


def hover9l(event):
    btn9["bg"] = bg
    copyinf.config(text=copyinf_d)


def hover10(event):
    btn10["bg"] = hoverbg
    copyinf.config(
        text="Alḥamdulillāh (All praises and thanks are due to Allāh) (ALT + 0)")


def hover10l(event):
    btn10["bg"] = bg
    copyinf.config(text=copyinf_d)


def hover11(event):
    btn11["bg"] = hoverbg
    copyinf.config(
        text="Jazāk Allāhu Khairan (May Allāh give you good) (ALT + - (Dash Symbol) )")


def hover11l(event):
    btn11["bg"] = bg
    copyinf.config(text=copyinf_d)


def hover12(event):
    btn12["bg"] = hoverbg
    copyinf.config(
        text="Bāraka Allāhu Feek (May Allāh bless you) (ALT + = (Equal Symbol) )")


def hover12l(event):
    btn12["bg"] = bg
    copyinf.config(text=copyinf_d)


def hover13(event):
    btn13["bg"] = hoverbg
    copyinf.config(
        text="As Salāmu ‘Alaikum (Peace be upon you) (ALT + [ (Left Square Bracket Symbol) )")


def hover13l(event):
    btn13["bg"] = bg
    copyinf.config(text=copyinf_d)


def hover14(event):
    btn14["bg"] = hoverbg
    copyinf.config(
        text="ʾIn shāʾ Allāh (If Allāh wills) (ALT + ] (Right Square Bracket Symbol) )")


def hover14l(event):
    btn14["bg"] = bg
    copyinf.config(text=copyinf_d)


def hoverc(event):
    copyrighttxt["fg"] = "gray"
    copyinf.config(text="Go to the Islāmic Text Copier website.")


def hovercl(event):
    copyrighttxt["fg"] = "white"
    copyinf.config(text=copyinf_d)

# gui


copyinf_d = "Hover over a text to see it's meaning in English"
copyinf = Label(text=copyinf_d, font=(regfont, 12), bg=bg, fg="white")
copyinf.pack(side="bottom", pady=15)

btn1_img = Image.open("resources/1.png")
btn1_img_resized = btn1_img.resize(
    (int(btn1_img.width * dpiscale), int(btn1_img.height * dpiscale)), Image.Resampling.LANCZOS)
btn1_img = ImageTk.PhotoImage(btn1_img_resized)

btn2_img = Image.open("resources/2.png")
btn2_img_resized = btn2_img.resize(
    (int(btn2_img.width * dpiscale), int(btn2_img.height * dpiscale)), Image.Resampling.LANCZOS)
btn2_img = ImageTk.PhotoImage(btn2_img_resized)

btn3_img = Image.open("resources/3.png")
btn3_img_resized = btn3_img.resize(
    (int(btn3_img.width * dpiscale), int(btn3_img.height * dpiscale)), Image.Resampling.LANCZOS)
btn3_img = ImageTk.PhotoImage(btn3_img_resized)

btn4_img = Image.open("resources/4.png")
btn4_img_resized = btn4_img.resize(
    (int(btn4_img.width * dpiscale), int(btn4_img.height * dpiscale)), Image.Resampling.LANCZOS)
btn4_img = ImageTk.PhotoImage(btn4_img_resized)

btn5_img = Image.open("resources/5.png")
btn5_img_resized = btn5_img.resize(
    (int(btn5_img.width * dpiscale), int(btn5_img.height * dpiscale)), Image.Resampling.LANCZOS)
btn5_img = ImageTk.PhotoImage(btn5_img_resized)

btn6_img = Image.open("resources/6.png")
btn6_img_resized = btn6_img.resize(
    (int(btn6_img.width * dpiscale), int(btn6_img.height * dpiscale)), Image.Resampling.LANCZOS)
btn6_img = ImageTk.PhotoImage(btn6_img_resized)

btn7_img = Image.open("resources/7.png")
btn7_img_resized = btn7_img.resize(
    (int(btn7_img.width * dpiscale), int(btn7_img.height * dpiscale)), Image.Resampling.LANCZOS)
btn7_img = ImageTk.PhotoImage(btn7_img_resized)

btn8_img = Image.open("resources/8.png")
btn8_img_resized = btn8_img.resize(
    (int(btn8_img.width * dpiscale), int(btn8_img.height * dpiscale)), Image.Resampling.LANCZOS)
btn8_img = ImageTk.PhotoImage(btn8_img_resized)

btn9_img = Image.open("resources/9.png")
btn9_img_resized = btn9_img.resize(
    (int(btn9_img.width * dpiscale), int(btn9_img.height * dpiscale)), Image.Resampling.LANCZOS)
btn9_img = ImageTk.PhotoImage(btn9_img_resized)

btn10_img = Image.open("resources/10.png")
btn10_img_resized = btn10_img.resize(
    (int(btn10_img.width * dpiscale), int(btn10_img.height * dpiscale)), Image.Resampling.LANCZOS)
btn10_img = ImageTk.PhotoImage(btn10_img_resized)

btn11_img = Image.open("resources/11.png")
btn11_img_resized = btn11_img.resize(
    (int(btn11_img.width * dpiscale), int(btn11_img.height * dpiscale)), Image.Resampling.LANCZOS)
btn11_img = ImageTk.PhotoImage(btn11_img_resized)

btn12_img = Image.open("resources/12.png")
btn12_img_resized = btn12_img.resize(
    (int(btn12_img.width * dpiscale), int(btn12_img.height * dpiscale)), Image.Resampling.LANCZOS)
btn12_img = ImageTk.PhotoImage(btn12_img_resized)

btn13_img = Image.open("resources/13.png")
btn13_img_resized = btn13_img.resize(
    (int(btn13_img.width * dpiscale), int(btn13_img.height * dpiscale)), Image.Resampling.LANCZOS)
btn13_img = ImageTk.PhotoImage(btn13_img_resized)

btn14_img = Image.open("resources/14.png")
btn14_img_resized = btn14_img.resize(
    (int(btn14_img.width * dpiscale), int(btn14_img.height * dpiscale)), Image.Resampling.LANCZOS)
btn14_img = ImageTk.PhotoImage(btn14_img_resized)

copyrighttxt = Label(text="© Nāṣir ʿAṭif\nv2.5", bg=bg,
                     fg="white", font=(regfont, 12))
copyrighttxt.place(x=8, y=8)
copyrighttxt.bind("<Enter>", hoverc)
copyrighttxt.bind("<Leave>", hovercl)
copyrighttxt.bind("<Button-1>", lambda e: homeurl(homeurl))

docubtn = Button(text="Documentation", command=hmsg, font=(regfont, 12), bg=docubtn_bg,
                 activebackground=docubtn_bg, fg="white", activeforeground="white", borderwidth=0)
docubtn.place(relx=0.5, rely=0.12, anchor=CENTER)
docubtn.bind("<Enter>", hoverh)
docubtn.bind("<Leave>", hoverhl)

btn1 = Button(root, command=btn1, image=btn1_img,
              bg=bg, activebackground=bg, borderwidth=0)
btn1.place(relx=0.13, rely=0.24)
btn1.bind("<Enter>", hover1)
btn1.bind("<Leave>", hover1l)

btn2 = Button(root, command=btn2, image=btn2_img,
              bg=bg, activebackground=bg, borderwidth=0)
btn2.place(relx=0.24, rely=0.26)
btn2.bind("<Enter>", hover2)
btn2.bind("<Leave>", hover2l)

btn3 = Button(root, command=btn3, image=btn3_img,
              bg=bg, activebackground=bg, borderwidth=0)
btn3.place(relx=0.33, rely=0.29)
btn3.bind("<Enter>", hover3)
btn3.bind("<Leave>", hover3l)

btn4 = Button(root, command=btn4, image=btn4_img,
              bg=bg, activebackground=bg, borderwidth=0)
btn4.place(relx=0.54, rely=0.28)
btn4.bind("<Enter>", hover4)
btn4.bind("<Leave>", hover4l)

btn5 = Button(root, command=btn5, image=btn5_img,
              bg=bg, activebackground=bg, borderwidth=0)
btn5.place(relx=0.67, rely=0.27)
btn5.bind("<Enter>", hover5)
btn5.bind("<Leave>", hover5l)

btn6 = Button(root, command=btn6, image=btn6_img,
              bg=bg, activebackground=bg, borderwidth=0)
btn6.place(relx=0.14, rely=0.45)
btn6.bind("<Enter>", hover6)
btn6.bind("<Leave>", hover6l)

btn7 = Button(root, command=btn7, image=btn7_img,
              bg=bg, activebackground=bg, borderwidth=0)
btn7.place(relx=0.34, rely=0.45)
btn7.bind("<Enter>", hover7)
btn7.bind("<Leave>", hover7l)

btn8 = Button(root, command=btn8, image=btn8_img,
              bg=bg, activebackground=bg, borderwidth=0)
btn8.place(relx=0.49, rely=0.45)
btn8.bind("<Enter>", hover8)
btn8.bind("<Leave>", hover8l)

btn9 = Button(root, command=btn9, image=btn9_img,
              bg=bg, activebackground=bg, borderwidth=0)
btn9.place(relx=0.65, rely=0.46)
btn9.bind("<Enter>", hover9)
btn9.bind("<Leave>", hover9l)

btn10 = Button(root, command=btn10, image=btn10_img,
               bg=bg, activebackground=bg, borderwidth=0)
btn10.place(relx=0.14, rely=0.62)
btn10.bind("<Enter>", hover10)
btn10.bind("<Leave>", hover10l)

btn11 = Button(root, command=btn11, image=btn11_img,
               bg=bg, activebackground=bg, borderwidth=0)
btn11.place(relx=0.29, rely=0.62)
btn11.bind("<Enter>", hover11)
btn11.bind("<Leave>", hover11l)

btn12 = Button(root, command=btn12, image=btn12_img,
               bg=bg, activebackground=bg, borderwidth=0)
btn12.place(relx=0.49, rely=0.62)
btn12.bind("<Enter>", hover12)
btn12.bind("<Leave>", hover12l)

btn13 = Button(root, command=btn13, image=btn13_img,
               bg=bg, activebackground=bg, borderwidth=0)
btn13.place(relx=0.69, rely=0.63)
btn13.bind("<Enter>", hover13)
btn13.bind("<Leave>", hover13l)

btn14 = Button(root, command=btn14, image=btn14_img,
               bg=bg, activebackground=bg, borderwidth=0)
btn14.place(relx=0.14, rely=0.75)
btn14.bind("<Enter>", hover14)
btn14.bind("<Leave>", hover14l)

# check if the system is connected to the internet before checking for updates
# otherwise itc would crash


def testnet():
    try:
        create_connection(("itc.nasiratif.net", 443))
        return True
    except OSError:
        return False


isconnected = testnet()

# check for updates

# set current version of itc in this variable:
itcversion = 21

if isconnected == True:
    request = get("http://itc.nasiratif.net/version.txt")
    open("version.txt", "wb").write(request.content)

    if path.isfile(r"version.txt"):
        f = open(r"version.txt", "r")
        fileversion = f.read() .replace("\n", "").strip()
        if float(fileversion) > float(itcversion):
            f.close()
            updatemsg = messagebox.askquestion(
                title="Update Available", message="Alḥamdulillāh, an update is available. Go to the home page to download it?")
            if updatemsg == "yes":
                webbrowser.open("http://itc.nasiratif.net")
                root.destroy()

root.mainloop()
