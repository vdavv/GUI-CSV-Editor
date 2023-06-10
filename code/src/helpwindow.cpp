#include "helpwindow.h"
#include "ui_helpwindow.h"

HelpWindow::HelpWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HelpWindow)
{
    ui->setupUi(this);
    logoWindow = nullptr; // initialize logoWindow to nullptr

    connect(ui->okButtonHelp, &QPushButton::clicked, this, &HelpWindow::on_okButtonHelp_clicked);
    connect(ui->logoButtonHelp, &QPushButton::clicked, this, &HelpWindow::on_logoButtonHelp_clicked);
    connect(ui->languageHelpBox, SIGNAL(currentIndexChanged(int)), this, SLOT(onLanguageBoxChanged(int)));
}


HelpWindow::~HelpWindow()
{
    delete ui;
}


void HelpWindow::on_okButtonHelp_clicked()
{
    this->close();
}


void HelpWindow::on_logoButtonHelp_clicked()
{
    // Check if the logoWindow is already open
    if(logoWindow == nullptr)
    {
        logoWindow = new LogoWindow(this, lang);
        logoWindow->setAttribute(Qt::WA_DeleteOnClose); // Set the attribute so that the window is deleted when it's closed
        logoWindow->show();

        // Connect the logoWindow's close signal to a lambda function that sets logoWindow to nullptr
        connect(logoWindow, &QWidget::destroyed, [this]() {
            this->logoWindow = nullptr;
        });
    }
}


void HelpWindow::onLanguageBoxChanged(int index)
{
    // index 0 = English (default)
    // index 1 = Russian (optional)
    translateUi(index);
    lang = index;
    emit languageChanged(index);
}


void HelpWindow::translateUi(int lang)
{
    switch(lang)
    {
    case 1:
        setWindowTitle("Помощь");
        ui->logoButtonHelp->setText("Лого");
        ui->textBrowser->setHtml(R"(<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0//EN" "http://www.w3.org/TR/REC-html40/strict.dtd">
<html><head><meta name="qrichtext" content="1" /><meta charset="utf-8" /><style type="text/css">
p, li { white-space: pre-wrap; }
hr { height: 1px; border-width: 0; }
li.unchecked::marker { content: "\2610"; }
li.checked::marker { content: "\2612"; }
</style></head><body style=" font-family:'.AppleSystemUIFont'; font-size:13pt; font-weight:400; font-style:normal;">
<p style=" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"><span style=" font-family:'.AppleSystemUIFont','serif'; font-size:24pt; font-weight:700;">Об Этом</span> </p>
<p style=" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"><span style=" font-family:'.AppleSystemUIFont','serif'; font-weight:700;"> </span> </p>
<p style=" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"><span style=" font-family:'.AppleSystemUIFont','serif'; font-size:14pt;">Бюро переписи населения США регулярно собирает информацию по многим городским районам Соединенных Штатов, включая данные о количестве врачей и количестве (и размере) больниц. Этот набор данных содержит такую информацию по 83 различным городским районам.</span> </p>
<p style=" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"><span style=" font-family:'.AppleSystemUIFont','serif';"> </span> </p>
<p style="-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"><br /></p>
<p style="-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"><br /></p>
<p style=" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"><span style=" font-family:'.AppleSystemUIFont','serif'; font-size:24pt; font-weight:700;">Функционал</span> </p>
<p style=" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"><span style=" font-family:'.AppleSystemUIFont','serif'; font-weight:700;"> </span> </p>
<p style=" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"><span style=" font-family:'.AppleSystemUIFont','serif'; font-size:18pt;">Базовый:</span><span style=" font-size:18pt;"> </span></p>
<p style=" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"><span style=" font-family:'Symbol';">·</span><span style=" font-family:'Times New Roman'; font-size:7pt;">     </span>Добавьте строку с помощью кнопки “Добавить”. </p>
<p style=" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"><span style=" font-family:'Symbol';">·</span><span style=" font-family:'Times New Roman'; font-size:7pt;">     </span>Отредактируйте строку с помощью кнопки “Редактировать”. </p>
<p style=" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"><span style=" font-family:'Symbol';">·</span><span style=" font-family:'Times New Roman'; font-size:7pt;">     </span>Удалите строку с помощью кнопки “Удалить”. </p>
<p style=" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"><span style=" font-family:'Symbol';">·</span><span style=" font-family:'Times New Roman'; font-size:7pt;">     </span>Сохраните текущую таблицу в исходный файл с помощью кнопки “Сохранить”. </p>
<p style=" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"><span style=" font-family:'Symbol';">·</span><span style=" font-family:'Times New Roman'; font-size:7pt;">     </span>Загрузите данные из исходного файла с помощью кнопки "Обновить" </p>
<p style=" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"><span style=" font-family:'Symbol';">·</span><span style=" font-family:'Times New Roman'; font-size:7pt;">     </span>Отобразите логотип приложения с помощью кнопки “Лого”. </p>
<p style=" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"><span style=" font-family:'Symbol';">·</span><span style=" font-family:'Times New Roman'; font-size:7pt;">     </span>Отредактируйте любую ячейку, дважды щелкнув по ней. </p>
<p style=" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"><span style=" font-family:'Symbol';">·</span><span style=" font-family:'Times New Roman'; font-size:7pt;">     </span>Просмотрите информацию о любой строке, нажав на ее номер слева от таблицы. </p>
<p style=" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;">    </p>
<p style=" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"><span style=" font-size:18pt;">Продвинутый: </span>  </p>
<p style=" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"><span style=" font-family:'Symbol';">·</span><span style=" font-family:'Times New Roman'; font-size:7pt;">     </span>Отмените добавление, редактирование или удаление, нажав кнопку "Назад".</p>
<p style=" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"><span style=" font-family:'Symbol';">·</span><span style=" font-family:'Times New Roman'; font-size:7pt;">     </span>Отсортируйте данные, выбрав параметр в поле со списком, по умолчанию указывающий “Не Отсортировано”. </p>
<p style=" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"><span style=" font-family:'Symbol';">·</span><span style=" font-family:'Times New Roman'; font-size:7pt;">     </span>Измените порядок сортировки в обратном порядке, нажав маленький переключатель слева от поля со списком. </p>
<p style=" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"><span style=" font-family:'Symbol';">·</span><span style=" font-family:'Times New Roman'; font-size:7pt;">     </span>Сортировка осуществляется щелчком по заголовку столбца. </p>
<p style=" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"><span style=" font-family:'Symbol';">·</span><span style=" font-family:'Times New Roman'; font-size:7pt;">     </span>Измените порядок сортировки в обратном порядке, дважды щелкнув по заголовку того же столбца. </p>
<p style=" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"><span style=" font-family:'Symbol';">·</span><span style=" font-family:'Times New Roman'; font-size:7pt;">     </span>Отфильтруйте данные по любому параметру, нажав на кнопку “Фильтры”. </p>
<p style=" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;">  </p>
<p style="-qt-paragraph-type:empty; margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"><br /></p>
<p style=" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"><span style=" font-size:24pt; font-weight:700;">Автор</span></p>
<p style=" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"><span style=" font-size:18pt;">Создал студент DSBA222-1</span></p>
<p style=" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"><span style=" font-size:24pt; font-weight:700;"> Панкин Алексей</span></p></body></html>)");
        return;


    default:
        setWindowTitle("Help");
        ui->logoButtonHelp->setText("Logo");
        ui->textBrowser->setHtml(R"(<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0//EN" "http://www.w3.org/TR/REC-html40/strict.dtd">
<html><head><meta name="qrichtext" content="1" /><meta charset="utf-8" /><style type="text/css">
p, li { white-space: pre-wrap; }
hr { height: 1px; border-width: 0; }
li.unchecked::marker { content: "\2610"; }
li.checked::marker { content: "\2612"; }
</style></head><body style=" font-family:'.AppleSystemUIFont'; font-size:13pt; font-weight:400; font-style:normal;">
<p style=" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"><span style=" font-family:'.AppleSystemUIFont','serif'; font-size:24pt; font-weight:700;">About</span> </p>
<p style=" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"><span style=" font-family:'.AppleSystemUIFont','serif'; font-weight:700;"> </span> </p>
<p style=" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"><span style=" font-family:'.AppleSystemUIFont','serif'; font-size:14pt;">The U.S. Census Bureau regularly collects information for many metropolitan areas in the United States, including data on number of physicians and number (and size) of hospitals. This dataset has such information for 83 different metropolitan areas.</span> </p>
<p style=" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"><span style=" font-family:'.AppleSystemUIFont','serif';"> </span> </p>
<p style="-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"><br /></p>
<p style="-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"><br /></p>
<p style=" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"><span style=" font-family:'.AppleSystemUIFont','serif'; font-size:24pt; font-weight:700;">Functionality</span> </p>
<p style=" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"><span style=" font-family:'.AppleSystemUIFont','serif'; font-weight:700;"> </span> </p>
<p style=" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"><span style=" font-family:'.AppleSystemUIFont','serif'; font-size:18pt;">Basic:</span><span style=" font-size:18pt;"> </span></p>
<p style=" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"><span style=" font-family:'Symbol';">·</span><span style=" font-family:'Times New Roman'; font-size:7pt;">     </span>Add row via “Add” button. </p>
<p style=" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"><span style=" font-family:'Symbol';">·</span><span style=" font-family:'Times New Roman'; font-size:7pt;">     </span>Edit row via “Edit” button. </p>
<p style=" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"><span style=" font-family:'Symbol';">·</span><span style=" font-family:'Times New Roman'; font-size:7pt;">     </span>Delete row via “Delete” button. </p>
<p style=" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"><span style=" font-family:'Symbol';">·</span><span style=" font-family:'Times New Roman'; font-size:7pt;">     </span>Save the current table to the original file via “Save” button. </p>
<p style=" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"><span style=" font-family:'Symbol';">·</span><span style=" font-family:'Times New Roman'; font-size:7pt;">     </span>Load data from the original file losing the data in the table. </p>
<p style=" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"><span style=" font-family:'Symbol';">·</span><span style=" font-family:'Times New Roman'; font-size:7pt;">     </span>Display the app logo via “Logo” button. </p>
<p style=" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"><span style=" font-family:'Symbol';">·</span><span style=" font-family:'Times New Roman'; font-size:7pt;">     </span>Edit any cell by double-clicking on it. </p>
<p style=" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"><span style=" font-family:'Symbol';">·</span><span style=" font-family:'Times New Roman'; font-size:7pt;">     </span>View the info of any row by clicking on its number to the left of the table. </p>
<p style=" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;">    </p>
<p style=" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"><span style=" font-size:18pt;">Advanced: </span>  </p>
<p style=" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"><span style=" font-family:'Symbol';">·</span><span style=" font-family:'Times New Roman'; font-size:7pt;">     </span>Undo add, edit or delete action by clicking &quot;Undo&quot; button.</p>
<p style=" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"><span style=" font-family:'Symbol';">·</span><span style=" font-family:'Times New Roman'; font-size:7pt;">     </span>Sort data by choosing the parameter in combo box by default stating “Not Sorted”. </p>
<p style=" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"><span style=" font-family:'Symbol';">·</span><span style=" font-family:'Times New Roman'; font-size:7pt;">     </span>Reverse the sort order by clicking small radio button to the left of the combo box. </p>
<p style=" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"><span style=" font-family:'Symbol';">·</span><span style=" font-family:'Times New Roman'; font-size:7pt;">     </span>Sort by clicking on the column header. </p>
<p style=" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"><span style=" font-family:'Symbol';">·</span><span style=" font-family:'Times New Roman'; font-size:7pt;">     </span>Reverse the sort order by double-clicking on the same column header. </p>
<p style=" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"><span style=" font-family:'Symbol';">·</span><span style=" font-family:'Times New Roman'; font-size:7pt;">     </span>Filter the data based on any parameter via pressing on the “Filter” button. </p>
<p style=" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;">  </p>
<p style="-qt-paragraph-type:empty; margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"><br /></p>
<p style=" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"><span style=" font-size:24pt; font-weight:700;">Author</span></p>
<p style=" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"><span style=" font-size:18pt;">Authored by DSBA222-1 student</span></p>
<p style=" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"><span style=" font-size:24pt; font-weight:700;"> Pankin Aleksei</span></p></body></html>)");
        return;
    }
}
