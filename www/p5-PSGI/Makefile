# $NetBSD: Makefile,v 1.1.1.1 2010/04/10 12:45:41 seb Exp $

DISTNAME=	PSGI-1.03
PKGNAME=	p5-${DISTNAME}
#PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MI/MIYAGAWA/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/PSGI/
COMMENT=	Perl Web Server Gateway Interface Specification
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/PSGI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
