# $NetBSD: Makefile,v 1.43 2012/10/03 21:59:09 wiz Exp $
#

PKG_DESTDIR_SUPPORT=	user-destdir

.include "Makefile.common"

PKGNAME=		p5-gtk-${GTKPERL_VERSION}
PKGREVISION=		11
SVR4_PKGNAME=		p5gtk

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Perl bindings for GTK+

MAKE_JOBS_SAFE=		no

WRKSRC=			${WRKDIR}/${DISTNAME}/Gtk
MAKE_PARAMS=		INSTALLMAN3DIR=${PREFIX}/${PKGMANDIR}/man3
PERL5_PACKLIST=		auto/Gtk/.packlist

REPLACE_PERL+=		../tools/*

.include "../../lang/perl5/module.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
