# $NetBSD: Makefile,v 1.32 2023/07/06 09:42:23 wiz Exp $

DISTNAME=	CGI-FastTemplate-1.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	17
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/CGI-FastTemplate
COMMENT=	Perl5 extension for managing templates
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/CGI/FastTemplate/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
