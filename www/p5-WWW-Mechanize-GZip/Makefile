# $NetBSD: Makefile,v 1.7 2014/05/29 23:38:16 wiz Exp $

DISTNAME=	WWW-Mechanize-GZip-0.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=WWW/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/WWW-Mechanize-GZip/
COMMENT=	Perl 5 module to fetch webpages with gzip-compression
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/WWW/Mechanize/GZip/.packlist

DEPENDS+=	p5-Test-WWW-Mechanize-[0-9]*:../../www/p5-Test-WWW-Mechanize

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
