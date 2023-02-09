#ifndef LISTVIEWITEMDELEGATEICONS_H
#define LISTVIEWITEMDELEGATEICONS_H

#include <QObject>
#include <QItemDelegate>

class ListViewItemDelegateIcons : public QItemDelegate
{
    Q_OBJECT
public:
    explicit ListViewItemDelegateIcons();

    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};

#endif // LISTVIEWITEMDELEGATEICONS_H
