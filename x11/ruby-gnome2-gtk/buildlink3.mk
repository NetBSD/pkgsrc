# $NetBSD: buildlink3.mk,v 1.9 2011/01/13 13:36:37 wiz Exp $
#

BUILDLINK_TREE+=	ruby-gnome2-gtk

.if !defined(RUBY_GNOME2_GTK_BUILDLINK3_MK)
RUBY_GNOME2_GTK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ruby-gnome2-gtk+=	${RUBY_PKGPREFIX}-gnome2-gtk>=0.17.0
BUILDLINK_ABI_DEPENDS.ruby-gnome2-gtk?=	ruby18-gnome2-gtk>=0.90.5nb1
BUILDLINK_PKGSRCDIR.ruby-gnome2-gtk?=	../../x11/ruby-gnome2-gtk

.include "../../devel/ruby-gnome2-glib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # RUBY_GNOME2_GTK_BUILDLINK3_MK

BUILDLINK_TREE+=	-ruby-gnome2-gtk
