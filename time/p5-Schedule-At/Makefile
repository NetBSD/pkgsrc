# $NetBSD: Makefile,v 1.1.1.1 2011/05/18 01:29:20 dmcmahill Exp $

DISTNAME=	Schedule-At-1.10
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/J/JO/JOSERODR/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Schedule-At/
COMMENT=	OS independent interface to the Unix 'at' command
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Schedule/At/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
