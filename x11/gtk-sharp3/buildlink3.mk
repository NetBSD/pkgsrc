# $NetBSD: buildlink3.mk,v 1.3 2020/02/12 01:32:43 nia Exp $

BUILDLINK_TREE+=	gtk-sharp3

.if !defined(GTK_SHARP3_BUILDLINK3_MK)
GTK_SHARP3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtk-sharp3+=	gtk-sharp>=2.99.3
BUILDLINK_PKGSRCDIR.gtk-sharp3?=	../../x11/gtk-sharp3
BUILDLINK_CONTENTS_FILTER.gtk-sharp3=	${EGREP} '(^include/|^lib/)'
.endif	# GTK_SHARP3_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtk-sharp3
