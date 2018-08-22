# $NetBSD: Makefile,v 1.15 2018/08/22 09:47:29 wiz Exp $

DISTNAME=	CGI-Cookie-Splitter-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES+=	${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/CGI-Cookie-Splitter/
COMMENT=	Perl5 module for splitting big cookies into smaller ones
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/CGI/Cookie/Splitter/.packlist

DEPENDS+=	p5-CGI-Simple-[0-9]*:../../www/p5-CGI-Simple
BUILD_DEPENDS+=	p5-Test-Simple>=1.001010:../../devel/p5-Test-Simple

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
