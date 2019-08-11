# $NetBSD: Makefile,v 1.17 2019/08/11 13:24:26 wiz Exp $

DISTNAME=	CGI-Cookie-Splitter-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	www perl5
MASTER_SITES+=	${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/CGI-Cookie-Splitter
COMMENT=	Perl5 module for splitting big cookies into smaller ones
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/CGI/Cookie/Splitter/.packlist

DEPENDS+=	p5-CGI-Simple-[0-9]*:../../www/p5-CGI-Simple
BUILD_DEPENDS+=	p5-Test-Simple>=1.001010:../../devel/p5-Test-Simple

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
