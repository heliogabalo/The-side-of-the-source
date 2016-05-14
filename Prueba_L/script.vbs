Set objArgs = WScript.Arguments
InputName = objArgs(0)
OutputName = objArgs(1)
Set objExcel = CreateObject("Excel.application")
objExcel.application.visible=false
objExcel.application.displayalerts=false
set objExcelBook = objExcel.Workbooks.Open(InputName)
objExcelBook.SaveAs OutputName, 23
objExcel.Application.Quit
objExcel.Quit
