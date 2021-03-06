// because we put the following lines in the metadata.desktop file, we have access
// to the FileDialog and LaunchApp extensions.
//
// X-Plasma-RequiredExtensions=FileDialog
// X-Plasma-OptionalExtensions=LaunchApp
//
// More documentation can be found here:
//
// http://techbase.kde.org/Development/Tutorials/Plasma/JavaScript/API#Extensions

function showOpenFileDialog()
{
    print("opening a file?")
    var dialog = new OpenFileDialog
    dialog.accepted.connect(openFileDialogAccepted)
    dialog.finished.connect(openFileDialogFinished)
    dialog.show()
}

function openFileDialogAccepted(dialog)
{
    var url = dialog.url
    print("open this file! " + url.protocol + ' ' + url.host + ' ' + url.path)
    /*
    var urls = new Array
    urls.push(url)
    plasmoid.runApplication("kate", urls)
    */
    if (plasmoid['openUrl']) {
        plasmoid.openUrl(url);
    } else {
        print("no openUrl method available to us!")
    }
}

function openFileDialogFinished(dialog)
{
    dialog.accepted.disconnect(openFileDialogAccepted)
    dialog.finished.disconnect(openFileDialogFinished)
    plasmoid.gc()
}

function showSaveFileDialog()
{
    print("saving a file?")
    var dialog = new SaveFileDialog
    dialog.accepted.connect(saveFileDialogAccepted)
    dialog.finished.connect(saveFileDialogFinished)
    dialog.show()
}

function saveFileDialogAccepted(dialog)
{
    print("save to this file! " + dialog.files)
}

function saveFileDialogFinished(dialog)
{
    dialog.accepted.disconnect(saveFileDialogAccepted)
    dialog.finished.disconnect(saveFileDialogFinished)
    plasmoid.gc()
}

open = new PushButton
open.text = i18n("Open File")
open.clicked.connect(showOpenFileDialog)

save = new PushButton
save.text = i18n("Save File")
save.clicked.connect(showSaveFileDialog)

layout = new LinearLayout
layout.orientation = QtVertical
layout.addItem(open)
layout.addItem(save)

