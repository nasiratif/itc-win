# Islāmic Text Copier Revision 3
# © ناصر عاطف (Nāṣir ʿAṭif)

from tkinter import *
from customtkinter import *
from pyperclip import *
from pyautogui import *
from keyboard import *
from os import path, remove
from requests import get
from socket import create_connection
import webbrowser
from threading import *
from subprocess import *
from platform import *

user_platform = system()
print("Running on " + user_platform)

# theming

set_default_color_theme("itc.theme.json")
app_font = "Calibri"
app_symbol_font_size = 35

# result in smaller symbol font size if the platform is macOS, since it uses a weird font for Arabic symbols

#if user_platform == "darwin":
#    app_symbol_font_size = app_symbol_font_size - 15

# import startile if the platform is windows

if user_platform == "Windows":
    from os import startfile

# delete version.txt file when closing

def clear():
    try:
        print("ITC preparing to quit")
        remove("version.txt")
        itc.quit()
    except:
        print("Version file not found, either way ITC preparing to quit")
        itc.quit()

winW = 580 # width of the window
winH = 350 # height of the window

scrW, scrH = size() # width and height of the user's computer
print("Screen resolution is " + str(scrW) + " x " + str(scrH))

# init window

itc = CTk()

# get user's DPI

ppi = round(itc.winfo_fpixels("1i"))
print("PPI is " + str(ppi))
dpiscale = ppi / 96

# correctly set the window's position

winW_DPI = winW * dpiscale
winH_DPI = winH * dpiscale

winX = (scrW / 2) - (winW_DPI / 2)
winY = (scrH / 2) - (winH_DPI / 2)

print("Calculated DPI scale is " + str(dpiscale))

itc.geometry(f"{winW}x{winH}+{int(winX)}+{int(winY)}")
itc.protocol("WM_DELETE_WINDOW", clear)
itc.minsize(winW, winH)
itc.resizable(0,1)
itc.iconbitmap("itc.icon.ico")
itc.title("Islāmic Text Copier")

# button copy functions

def copyJAL():
    copy(bJAL.cget("text"))
    hover_tip.configure(text="Just copied: " + bJAL.cget("text"))

def copySWT():
    copy(bSWT.cget("text"))
    hover_tip.configure(text="Just copied: " + bSWT.cget("text"))

def copyAZW():
    copy(bAZW.cget("text"))
    hover_tip.configure(text="Just copied: " + bAZW.cget("text"))

def copySAW():
    copy(bSAW.cget("text"))
    hover_tip.configure(text="Just copied: " + bSAW.cget("text"))

def copyRA():
    copy(bRA.cget("text"))
    hover_tip.configure(text="Just copied: " + bRA.cget("text"))

def copyRA2():
    copy(bRA2.cget("text"))
    hover_tip.configure(text="Just copied: " + bRA2.cget("text"))

def copyRAH():
    copy(bRAH.cget("text"))
    hover_tip.configure(text="Just copied: " + bRAH.cget("text"))

def copyHAF():
    copy(bHAF.cget("text"))
    hover_tip.configure(text="Just copied: " + bHAF.cget("text"))

def copyAS():
    copy(bAS.cget("text"))
    hover_tip.configure(text="Just copied: " + bAS.cget("text"))

def copyALH():
    copy(bALH.cget("text"))
    hover_tip.configure(text="Just copied: " + bALH.cget("text"))

def copyJZK():
    copy(bJZK.cget("text"))
    hover_tip.configure(text="Just copied: " + bJZK.cget("text"))

def copyBRK():
    copy(bBRK.cget("text"))
    hover_tip.configure(text="Just copied: " + bBRK.cget("text"))

def copyASL():
    copy(bASL.cget("text"))
    hover_tip.configure(text="Just copied: " + bASL.cget("text"))

def copyINS():
    copy(bINS.cget("text"))
    hover_tip.configure(text="Just copied: " + bINS.cget("text"))

def copyRA3():
    copy(bRA3.cget("text"))
    hover_tip.configure(text="Just copied: " + bRA3.cget("text"))

# functions

def enter_website(e):
    webbrowser.open("https://itc.nasiratif.net")

def open_doc():
    if user_platform == "Windows":
        startfile("ITC_Documentation.pdf")
    else:
        if user_platform == "darwin":
            Popen(["open", "ITC_Documentation.pdf"])

def update_link():
    webbrowser.open("https://itc.nasiratif.net")
    clear()

def unhover(e):
    hover_tip.configure(text=hover_tip_default)

def bDOC_hover(e):
    hover_tip.configure(text="View the documentation of Islāmic Text Copier")

def bUPD_hover(e):
    hover_tip.configure(text="Update Islāmic Text Copier")

def bJAL_hover(e):
    hover_tip.configure(text="Jalla Jalāluhu (Exalted is His Majesty) (ALT + 1)")

def bSWT_hover(e):
    hover_tip.configure(text="Subḥānahu wa Taʾālá (Glorious and Exalted is He) (ALT + 2)")

def bAZW_hover(e):
    hover_tip.configure(text="ʿAzza wa Jal (The Mighty and Majestic) (ALT + 3)")

def bSAW_hover(e):
    hover_tip.configure(text="ʿSallá Allāhu ʿAlayhī wa as-Salam (May Allāh's praise & salutations be upon him) (ALT + 4)")

def bRA_hover(e):
    hover_tip.configure(text="Raḍī Allāhu ʿAnhu (May Allāh be pleased with him) (ALT + 5)")

def bRA2_hover(e):
    hover_tip.configure(text="Raḍī Allāhu ʿAnhā (May Allāh be pleased with her) (ALT + 6)")

def bRAH_hover(e):
    hover_tip.configure(text="Raḥimahullāh (May Allah have mercy on him) (ALT + 7)")

def bHAF_hover(e):
    hover_tip.configure(text="Ḥafiẓahullāh (May Allah preserve him) (ALT + 8)")

def bAS_hover(e):
    hover_tip.configure(text="ʿAlayhī as-Salām (Peace be upon him) (ALT + 9)")

def bALH_hover(e):
    hover_tip.configure(text="Alḥamdulillāh (All praises and thanks are due to Allāh) (ALT + 0)")

def bJZK_hover(e):
    hover_tip.configure(text="Jazāk Allāhu Khairan (May Allāh give you good) (ALT + -)")

def bBRK_hover(e):
    hover_tip.configure(text="Bārik Allāhu Fīk (May Allāh bless you) (ALT + =)")

def bASL_hover(e):
    hover_tip.configure(text="As Salāmu ‘Alaikum (Peace be upon you) (ALT + [)")

def bINS_hover(e):
    hover_tip.configure(text="ʾIn shāʾ Allāh (If Allāh wills) (ALT + ])")

def bRA3_hover(e):
    hover_tip.configure(text="Raḍī Allāhu ʿAnhumā (May Allāh be pleased with them) (ALT + ;)")

def copyright_hover(e):
    copyright.configure(text_color="gray")
    hover_tip.configure(text="Go to the website of Islāmic Text Copier")

def copyright_unhover(e):
    copyright.configure(text_color="#DCE4EE")
    hover_tip.configure(text=hover_tip_default)

# labels

hover_tip_default = "Hover over a text to see it's meaning in English"
hover_tip = CTkLabel(master=itc, text=hover_tip_default, font=(app_font, 15))
hover_tip.pack(side="bottom", pady=6)

copyright = CTkLabel(master=itc, text="© ناصر عاطف\nv3.0", font=(app_font, 16))
copyright.bind("<Enter>", copyright_hover)
copyright.bind("<Leave>", copyright_unhover)
copyright.bind("<Button-1>", enter_website)
copyright.place(x=15, y=13)

# misc buttons

bDOC = CTkButton(master=itc, command=open_doc, text="View Documentation", width=50, height=32, font=(app_font, 14))
bDOC.bind("<Enter>", bDOC_hover)
bDOC.bind("<Leave>", unhover)
bDOC.pack(side=TOP, anchor=CENTER, pady=15)

bUPD = CTkButton(master=itc, command=update_link, text="Update Available!", width=50, height=30, font=(app_font, 15))
bUPD.bind("<Enter>", bUPD_hover)
bUPD.bind("<Leave>", unhover)

# copyable buttons

bJAL = CTkButton(master=itc, command=copyJAL, text="ﷻ", width=50, height=50, font=(app_font, app_symbol_font_size))
bJAL.bind("<Enter>", bJAL_hover)
bJAL.bind("<Leave>", unhover)
bJAL.place(relx=0.1, rely=0.20)

bSWT = CTkButton(master=itc, command=copySWT, text="سبحانه و تعالى", width=50, height=50, font=(app_font, 20))
bSWT.bind("<Enter>", bSWT_hover)
bSWT.bind("<Leave>", unhover)
bSWT.place(relx=0.22, rely=0.20)

bAZW = CTkButton(master=itc, command=copyAZW, text="عز و جل", width=50, height=50, font=(app_font, 20))
bAZW.bind("<Enter>", bAZW_hover)
bAZW.bind("<Leave>", unhover)
bAZW.place(relx=0.45, rely=0.20)

bSAW = CTkButton(master=itc, command=copySAW, text="ﷺ", width=50, height=50, font=(app_font, app_symbol_font_size))
bSAW.bind("<Enter>", bSAW_hover)
bSAW.bind("<Leave>", unhover)
bSAW.place(relx=0.61, rely=0.20)

bRA = CTkButton(master=itc, command=copyRA, text="رضي الله عنه", width=50, height=50, font=(app_font, 20))
bRA.bind("<Enter>", bRA_hover)
bRA.bind("<Leave>", unhover)
bRA.place(relx=0.73, rely=0.20)

bRA2 = CTkButton(master=itc, command=copyRA2, text="رضي الله عنها", width=50, height=50, font=(app_font, 20))
bRA2.bind("<Enter>", bRA2_hover)
bRA2.bind("<Leave>", unhover)
bRA2.place(relx=0.1, rely=0.39)

bRAH = CTkButton(master=itc, command=copyRAH, text="رحمه الله", width=50, height=50, font=(app_font, 20))
bRAH.bind("<Enter>", bRAH_hover)
bRAH.bind("<Leave>", unhover)
bRAH.place(relx=0.31, rely=0.39)

bHAF = CTkButton(master=itc, command=copyHAF, text="حفظه الله", width=50, height=50, font=(app_font, 20))
bHAF.bind("<Enter>", bHAF_hover)
bHAF.bind("<Leave>", unhover)
bHAF.place(relx=0.47, rely=0.39)

bAS = CTkButton(master=itc, command=copyAS, text="عليه السلام", width=50, height=50, font=(app_font, 20))
bAS.bind("<Enter>", bAS_hover)
bAS.bind("<Leave>", unhover)
bAS.place(relx=0.64, rely=0.39)

bALH = CTkButton(master=itc, command=copyALH, text="الحمد لله", width=50, height=50, font=(app_font, 20))
bALH.bind("<Enter>", bALH_hover)
bALH.bind("<Leave>", unhover)
bALH.place(relx=0.1, rely=0.58)

bJZK = CTkButton(master=itc, command=copyJZK, text="جزاك الله خيرا", width=50, height=50, font=(app_font, 20))
bJZK.bind("<Enter>", bJZK_hover)
bJZK.bind("<Leave>", unhover)
bJZK.place(relx=0.26, rely=0.58)

bBRK = CTkButton(master=itc, command=copyBRK, text="بارك الله فيك", width=50, height=50, font=(app_font, 20))
bBRK.bind("<Enter>", bBRK_hover)
bBRK.bind("<Leave>", unhover)
bBRK.place(relx=0.47, rely=0.58)

bASL = CTkButton(master=itc, command=copyASL, text="السلام عليكم", width=50, height=50, font=(app_font, 20))
bASL.bind("<Enter>", bASL_hover)
bASL.bind("<Leave>", unhover)
bASL.place(relx=0.67, rely=0.58)

bINS = CTkButton(master=itc, command=copyINS, text="إن شاء الله", width=50, height=40, font=(app_font, 16))
bINS.bind("<Enter>", bINS_hover)
bINS.bind("<Leave>", unhover)
bINS.place(relx=0.1, rely=0.77)

bRA3 = CTkButton(master=itc, command=copyRA3, text="رضي الله عنهما", width=50, height=40, font=(app_font, 16))
bRA3.bind("<Enter>", bRA3_hover)
bRA3.bind("<Leave>", unhover)
bRA3.place(relx=0.25, rely=0.77)

# hotkeys

add_hotkey("alt+1", lambda : copy(bJAL.cget("text")))
add_hotkey("alt+1", lambda : hover_tip.configure(text="Just copied: " + bJAL.cget("text")))

add_hotkey("alt+2", lambda : copy(bSWT.cget("text")))
add_hotkey("alt+2", lambda : hover_tip.configure(text="Just copied: " + bSWT.cget("text")))

add_hotkey("alt+3", lambda : copy(bAZW.cget("text")))
add_hotkey("alt+3", lambda : hover_tip.configure(text="Just copied: " + bAZW.cget("text")))

add_hotkey("alt+4", lambda : copy(bSAW.cget("text")))
add_hotkey("alt+4", lambda : hover_tip.configure(text="Just copied: " + bSAW.cget("text")))

add_hotkey("alt+5", lambda : copy(bRA.cget("text")))
add_hotkey("alt+5", lambda : hover_tip.configure(text="Just copied: " + bRA.cget("text")))

add_hotkey("alt+6", lambda : copy(bRA2.cget("text")))
add_hotkey("alt+6", lambda : hover_tip.configure(text="Just copied: " + bRA2.cget("text")))

add_hotkey("alt+7", lambda : copy(bRAH.cget("text")))
add_hotkey("alt+7", lambda : hover_tip.configure(text="Just copied: " + bRAH.cget("text")))

add_hotkey("alt+8", lambda : copy(bHAF.cget("text")))
add_hotkey("alt+8", lambda : hover_tip.configure(text="Just copied: " + bHAF.cget("text")))

add_hotkey("alt+9", lambda : copy(bAS.cget("text")))
add_hotkey("alt+9", lambda : hover_tip.configure(text="Just copied: " + bAS.cget("text")))

add_hotkey("alt+0", lambda : copy(bALH.cget("text")))
add_hotkey("alt+0", lambda : hover_tip.configure(text="Just copied: " + bALH.cget("text")))

add_hotkey("alt+-", lambda : copy(bJZK.cget("text")))
add_hotkey("alt+-", lambda : hover_tip.configure(text="Just copied: " + bJZK.cget("text")))

add_hotkey("alt+=", lambda : copy(bBRK.cget("text")))
add_hotkey("alt+=", lambda : hover_tip.configure(text="Just copied: " + bBRK.cget("text")))

add_hotkey("alt+[", lambda : copy(bASL.cget("text")))
add_hotkey("alt+[", lambda : hover_tip.configure(text="Just copied: " + bASL.cget("text")))

add_hotkey("alt+]", lambda : copy(bINS.cget("text")))
add_hotkey("alt+]", lambda : hover_tip.configure(text="Just copied: " + bINS.cget("text")))

add_hotkey("alt+;", lambda : copy(bRA3.cget("text")))
add_hotkey("alt+;", lambda : hover_tip.configure(text="Just copied: " + bRA3.cget("text")))

# update system

def update_itc():
    def test_connection():
        try:
            create_connection(("itc.nasiratif.net", 443))
            return True
        except:
            return False

    is_connected = test_connection()


    # set itc version here:

    itc_version = 23

    if is_connected == True:
        print("Checking for updates...")
        request = get("http://itc.nasiratif.net/version.txt")
        open("version.txt", "wb").write(request.content)

    if path.isfile(r"version.txt"):
        version_file = open(r"version.txt", "r")
        fileversion = version_file.read() .replace("\n", "").strip()
        if float(fileversion) > float(itc_version):
            version_file.close()
            bUPD.place(relx=0.77, y=15)
            print("An update is available")
        else:
            version_file.close()
            print("No updates available")

update_thread = Thread(target=update_itc, daemon=True)
update_thread.start()

itc.mainloop()