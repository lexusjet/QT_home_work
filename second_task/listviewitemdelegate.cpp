#include "listviewitemdelegate.h"
#include <QPainter>

ListViewItemDelegate::ListViewItemDelegate()
{

}

QSize ListViewItemDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return QItemDelegate::sizeHint(option, index);
}

void ListViewItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QString data = index.model()->data(index, Qt::DisplayRole).toString();


    QStyleOptionViewItem myOption = option;
            myOption.displayAlignment = Qt::AlignLeft;



    QPixmap pix(index.model()->data(index, Qt::DecorationRole).value<QPixmap>());

    drawDisplay(painter, myOption, myOption.rect, data);
    drawFocus(painter, myOption, myOption.rect);

    painter->drawPixmap(70,myOption.rect.y(),16,16, pix);
}
