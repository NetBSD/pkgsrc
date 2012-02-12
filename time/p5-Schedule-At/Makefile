# $NetBSD: Makefile,v 1.5 2012/02/12 06:27:14 hiramatsu Exp $

DISTNAME=	Schedule-At-1.14
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Schedule/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Schedule-At/
COMMENT=	OS independent interface to the Unix 'at' command
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Schedule/At/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir
TEST_ENV=	AT_CAN_EXEC=1

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
