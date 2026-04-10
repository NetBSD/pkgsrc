# $NetBSD: buildlink3.mk,v 1.38 2026/04/10 12:41:09 tsutsui Exp $

BUILDLINK_TREE+=	ruby-gtk3

.if !defined(RUBY_GTK3_BUILDLINK3_MK)
RUBY_GTK3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ruby-gtk3+=	${RUBY_PKGPREFIX}-gtk3>=4.3.6
BUILDLINK_ABI_DEPENDS.ruby-gtk3+=	${RUBY_PKGPREFIX}-gtk3>=4.3.6
BUILDLINK_PKGSRCDIR.ruby-gtk3?=		../../x11/ruby-gtk3

.include "../../graphics/ruby-gdk3/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif # RUBY_GTK3_BUILDLINK3_MK

BUILDLINK_TREE+=	-ruby-gtk3
