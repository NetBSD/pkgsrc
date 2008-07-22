# $NetBSD: Makefile,v 1.3 2008/07/22 13:48:48 rhaen Exp $

DISTNAME=	Calendar-Simple-1.20
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Calendar/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Calendar-Simple/
COMMENT=	Perl extension to create simple calendars

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST= auto/Calendar/Simple/.packlist

PERL5_MODULE_TYPE= Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
