# $NetBSD: Makefile,v 1.2 2014/05/29 23:38:01 wiz Exp $

DISTNAME=	CGI-Struct-1.21
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/CGI-Struct/
COMMENT=	Build structures from CGI data
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/CGI/Struct/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
