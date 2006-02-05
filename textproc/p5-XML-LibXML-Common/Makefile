# $NetBSD: Makefile,v 1.11 2006/02/05 23:11:04 joerg Exp $
#

DISTNAME=	XML-LibXML-Common-0.13
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
SVR4_PKGNAME=	p5xlc
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~phish/XML-LibXML-Common/
COMMENT=	Routines and constants common for XML::LibXML and XML::GDOME

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/XML/LibXML/Common/.packlist

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
