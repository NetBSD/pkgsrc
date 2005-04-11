# $NetBSD: Makefile,v 1.9 2005/04/11 21:47:39 tv Exp $

DISTNAME=	XML-NamespaceSupport-1.08
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-NamespaceSupport/
COMMENT=	Perl module to the SAX2 NamespaceSupport class

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/XML/NamespaceSupport/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
