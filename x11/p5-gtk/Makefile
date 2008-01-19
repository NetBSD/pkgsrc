# $NetBSD: Makefile,v 1.36 2008/01/19 09:16:26 wiz Exp $
#

.include "Makefile.common"

PKGNAME=		p5-gtk-${GTKPERL_VERSION}
PKGREVISION=		6
SVR4_PKGNAME=		p5gtk

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Perl bindings for GTK+

WRKSRC=			${WRKDIR}/${DISTNAME}/Gtk
MAKE_PARAMS=		INSTALLMAN3DIR=${PREFIX}/${PKGMANDIR}/man3
PERL5_PACKLIST=		auto/Gtk/.packlist

REPLACE_PERL+=		../tools/*

.include "../../lang/perl5/module.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
