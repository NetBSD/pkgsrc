# $NetBSD: buildlink3.mk,v 1.5 2004/01/15 20:50:15 rh Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GTK_BUILDLINK3_MK:=	${GTK_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gtk
.endif

.if !empty(GTK_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		gtk
BUILDLINK_DEPENDS.gtk?=		gtk+>=1.2.10
BUILDLINK_RECOMMENDED.gtk?=	gtk+>=1.2.10nb6
BUILDLINK_PKGSRCDIR.gtk?=	../../x11/gtk

USE_X11=	YES

.  include "../../devel/gettext-lib/buildlink3.mk"
.  include "../../devel/glib/buildlink3.mk"
.endif	# GTK_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
