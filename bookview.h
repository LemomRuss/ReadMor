#ifndef BOOKVIEW_H
#define BOOKVIEW_H

#include <QObject>
#include <QImage>

class bookView : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString title READ getTitle WRITE setTitle NOTIFY titleChanged)

    Q_PROPERTY(QString artBook READ getArtBook WRITE setArtBook NOTIFY artBookChanged)

public:

    bookView();

    bookView(QString title, QString artBook);

signals:
    void titleChanged();

    void artBookChanged();
public slots:
    QString getTitle();
    QString getArtBook();
    void setTitle(const QString &title);
    void setArtBook(const QString &artBook);

private:
    QString _title;
    QString _artBook;
};

#endif // BOOKVIEW_H

