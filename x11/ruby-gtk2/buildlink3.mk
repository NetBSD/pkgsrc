# $NetBSD: buildlink3.mk,v 1.2 2020/03/08 16:48:33 wiz Exp $

BUILDLINK_TREE+=	ruby-gtk2

.if !defined(RUBY_GTK2_BUILDLINK3_MK)
RUBY_GTK2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ruby-gtk2+=	${RUBY_PKGPREFIX}-gtk2>=3.3.8
BUILDLINK_ABI_DEPENDS.ruby-gtk2+=	${RUBY_PKGPREFIX}-gtk2>=3.4.1nb1
BUILDLINK_PKGSRCDIR.ruby-gtk2?=		../../x11/ruby-gtk2

.include "../../devel/ruby-pango/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # RUBY_GNOME2_GTK_BUILDLINK3_MK

BUILDLINK_TREE+=	-ruby-gtk2
