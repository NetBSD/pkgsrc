# $NetBSD: Makefile,v 1.20 2013/05/31 12:42:36 wiz Exp $

DISTNAME=	CGI-FastTemplate-1.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
SVR4_PKGNAME=	p5cgf
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/CGI-FastTemplate
COMMENT=	Perl5 extension for managing templates
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/CGI/FastTemplate/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
