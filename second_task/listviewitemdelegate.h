#ifndef LISTVIEWITEMDELEGATE_H
#define LISTVIEWITEMDELEGATE_H

#include <QObject>
#include <QItemDelegate>

class ListViewItemDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    explicit ListViewItemDelegate();

    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;

signals:

};

#endif // LISTVIEWITEMDELEGATE_H
