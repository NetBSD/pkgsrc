# $NetBSD: Makefile,v 1.14 2017/06/05 14:25:11 ryoon Exp $

DISTNAME=	CSS-Tiny-1.20
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CSS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/CSS-Tiny/
COMMENT=	Perl 5 module to read/write .css files with as little code as possible
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/CSS/Tiny/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
