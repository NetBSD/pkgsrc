# $NetBSD: buildlink3.mk,v 1.3 2015/04/06 08:17:18 adam Exp $

BUILDLINK_TREE+=	ocaml-lablgtk

.if !defined(OCAML_LABLGTK_BUILDLINK3_MK)
OCAML_LABLGTK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-lablgtk+=	ocaml-lablgtk>=2.6.0nb3
BUILDLINK_ABI_DEPENDS.ocaml-lablgtk+=	ocaml-lablgtk>=2.18.3nb2
BUILDLINK_PKGSRCDIR.ocaml-lablgtk?=	../../x11/ocaml-lablgtk

# gnome-panel must be exposed if and only if we built with it
pkgbase := ocaml-lablgtk
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.ocaml-lablgtk:Mgnomecanvas)
.  include "../../x11/gnome-panel/buildlink3.mk"
.endif

.endif # OCAML_LABLGTK_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-lablgtk
