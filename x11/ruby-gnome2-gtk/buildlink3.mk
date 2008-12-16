# $NetBSD: buildlink3.mk,v 1.1 2008/12/16 12:23:58 obache Exp $
#

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
RUBY_GNOME2_GTK_BUILDLINK3_MK:=	${RUBY_GNOME2_GTK_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	ruby-gnome2-gtk
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nruby-gnome2-gtk}
BUILDLINK_PACKAGES+=	ruby-gnome2-gtk
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}ruby-gnome2-gtk

.if ${RUBY_GNOME2_GTK_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.ruby-gnome2-gtk+=	${RUBY_PKGPREFIX}-gnome2-gtk>=0.17.0
BUILDLINK_PKGSRCDIR.ruby-gnome2-gtk?=	../../x11/ruby-gnome2-gtk
.endif	# RUBY_GNOME2_GTK_BUILDLINK3_MK

.include "../../devel/ruby-gnome2-glib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
