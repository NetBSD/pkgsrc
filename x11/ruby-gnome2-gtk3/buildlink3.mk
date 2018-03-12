# $NetBSD: buildlink3.mk,v 1.19 2018/03/12 11:15:58 wiz Exp $

BUILDLINK_TREE+=	ruby-gnome2-gtk3

.if !defined(RUBY_GNOME2_GTK3_BUILDLINK3_MK)
RUBY_GNOME2_GTK3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ruby-gnome2-gtk3+=	${RUBY_PKGPREFIX}-gnome2-gtk3>=1.2.0
BUILDLINK_ABI_DEPENDS.ruby-gnome2-gtk3+=	ruby24-gnome2-gtk3>=3.2.1nb2
BUILDLINK_ABI_DEPENDS.ruby-gnome2-gtk3?=	ruby23-gnome2-gtk3>=3.1.9nb1
BUILDLINK_PKGSRCDIR.ruby-gnome2-gtk3?=		../../x11/ruby-gnome2-gtk3

.include "../../devel/ruby-gnome2-glib/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif # RUBY_GNOME2_GTK3_BUILDLINK3_MK

BUILDLINK_TREE+=	-ruby-gnome2-gtk3
