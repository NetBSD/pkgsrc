# $NetBSD: Makefile,v 1.12 2010/08/21 16:36:56 seb Exp $

DISTNAME=	Kwiki-Icons-Gnome-0.15
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Kwiki/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.kwiki.org/
#HOMEPAGE=	http://search.cpan.org/dist/Kwiki-Icons-Gnome/
COMMENT=	Kwiki GNOME icons plugin

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Kwiki>=0.34:../../www/p5-Kwiki

PERL5_PACKLIST=		auto/Kwiki/Icons/Gnome/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
