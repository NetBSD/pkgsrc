# $NetBSD: buildlink3.mk,v 1.9 2004/03/18 09:12:16 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GTK_BUILDLINK3_MK:=	${GTK_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gtk
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngtk}
BUILDLINK_PACKAGES+=	gtk

.if !empty(GTK_BUILDLINK3_MK:M+)
BUILDLINK_PKGBASE.gtk?=		gtk+
BUILDLINK_DEPENDS.gtk+=		gtk+>=1.2.10
BUILDLINK_RECOMMENDED.gtk?=	gtk+>=1.2.10nb6
BUILDLINK_PKGSRCDIR.gtk?=	../../x11/gtk
.endif	# GTK_BUILDLINK3_MK

USE_X11=	yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
