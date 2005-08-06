# $NetBSD: Makefile,v 1.31 2005/08/06 06:19:41 jlam Exp $
#

.include "Makefile.common"

PKGNAME=		p5-gtk-${GTKPERL_VERSION}
PKGREVISION=		3
SVR4_PKGNAME=		p5gtk

MAINTAINER=		root@garbled.net
COMMENT=		Perl bindings for GTK+

WRKSRC=			${WRKDIR}/${DISTNAME}/Gtk
MAKE_PARAMS=		INSTALLMAN3DIR=${PREFIX}/man/man3
PERL5_PACKLIST=		auto/Gtk/.packlist

.include "../../lang/perl5/module.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
