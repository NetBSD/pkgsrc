# $NetBSD: Makefile,v 1.26 2004/01/20 12:28:27 agc Exp $
#

.include "Makefile.common"

PKGNAME=		p5-gtk-${GTKPERL_VERSION}
SVR4_PKGNAME=		p5gtk

MAINTAINER=		root@garbled.net
COMMENT=		Perl bindings for GTK+

WRKSRC=			${WRKDIR}/${DISTNAME}/Gtk
MAKE_PARAMS=		INSTALLMAN3DIR=${PREFIX}/man/man3
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Gtk/.packlist

.include "../../lang/perl5/module.mk"
.include "../../x11/gtk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
