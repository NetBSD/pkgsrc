# $NetBSD: buildlink3.mk,v 1.32 2025/08/30 22:46:46 wiz Exp $

BUILDLINK_TREE+=	ruby-gtk3

.if !defined(RUBY_GTK3_BUILDLINK3_MK)
RUBY_GTK3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ruby-gtk3+=	${RUBY_PKGPREFIX}-gtk3>=4.3.2
BUILDLINK_ABI_DEPENDS.ruby-gtk3+=	${RUBY_PKGPREFIX}-gtk3>=4.3.2nb1
BUILDLINK_PKGSRCDIR.ruby-gtk3?=		../../x11/ruby-gtk3

.include "../../graphics/ruby-gdk3/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif # RUBY_GTK3_BUILDLINK3_MK

BUILDLINK_TREE+=	-ruby-gtk3
