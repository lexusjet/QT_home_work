#include "listviewitemdelegateicons.h"
#include <QPainter>

ListViewItemDelegateIcons::ListViewItemDelegateIcons()
{

}

QSize ListViewItemDelegateIcons::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return QItemDelegate::sizeHint(option, index);
}

void ListViewItemDelegateIcons::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QString data = index.model()->data(index, Qt::DisplayRole).toString();


    QStyleOptionViewItem myOption = option;
            myOption.displayAlignment = Qt::AlignCenter | Qt::AlignBottom;



    QPixmap pix(index.model()->data(index, Qt::DecorationRole).value<QPixmap>());

    drawDisplay(painter, myOption, myOption.rect, data);
    drawFocus(painter, myOption, myOption.rect);

    painter->drawPixmap(myOption.rect.left() +10 ,myOption.rect.y(),16,16, pix);
}
