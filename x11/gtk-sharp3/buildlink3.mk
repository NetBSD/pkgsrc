# $NetBSD: buildlink3.mk,v 1.4 2022/06/28 11:37:53 wiz Exp $

BUILDLINK_TREE+=	gtk-sharp3

.if !defined(GTK_SHARP3_BUILDLINK3_MK)
GTK_SHARP3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtk-sharp3+=	gtk-sharp>=2.99.3
BUILDLINK_ABI_DEPENDS.gtk-sharp3?=	gtk-sharp>=2.99.3nb12
BUILDLINK_PKGSRCDIR.gtk-sharp3?=	../../x11/gtk-sharp3
BUILDLINK_CONTENTS_FILTER.gtk-sharp3=	${EGREP} '(^include/|^lib/)'
.endif	# GTK_SHARP3_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtk-sharp3
