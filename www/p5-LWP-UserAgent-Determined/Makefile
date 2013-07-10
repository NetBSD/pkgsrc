# $NetBSD: Makefile,v 1.9 2013/07/10 02:49:26 schmonz Exp $
#

DISTNAME=	LWP-UserAgent-Determined-1.06
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5lud
CATEGORIES=	www net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=LWP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/LWP-UserAgent-Determined/
COMMENT=	Perl5 virtual browser that retries errors
LICENSE=	gnu-gpl-v2 # OR artistic

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/LWP/UserAgent/Determined/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
