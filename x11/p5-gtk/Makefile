# $NetBSD: Makefile,v 1.24 2003/07/13 13:54:27 wiz Exp $
#

.include "Makefile.common"

PKGNAME=		p5-gtk-${GTKPERL_VERSION}
PKGREVISION=		2
SVR4_PKGNAME=		p5gtk
WRKSRC=			${WRKDIR}/${DISTNAME}/Gtk

MAINTAINER=		root@garbled.net
COMMENT=		Perl bindings for GTK+

MAKE_PARAMS=		INSTALLMAN3DIR=${PREFIX}/man/man3
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Gtk/.packlist

.include "../../lang/perl5/module.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
