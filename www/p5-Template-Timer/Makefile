# $NetBSD: Makefile,v 1.5 2011/08/14 16:06:09 obache Exp $

DISTNAME=	Template-Timer-1.00
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
SVR4_PKGNAME=	p5ttm
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Template/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Template-Timer/
COMMENT=	Rudimentary profiling for Template Toolkit
LICENSE=	gnu-gpl-v3 # OR artistic-2.0

DEPENDS+=	p5-Template-Toolkit>=2.0:../../www/p5-Template-Toolkit

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Template/Timer/.packlist

PKG_DESTDIR_SUPPORT=    user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
