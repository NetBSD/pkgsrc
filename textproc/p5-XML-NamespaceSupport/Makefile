# $NetBSD: Makefile,v 1.6 2004/01/05 22:16:25 jlam Exp $

DISTNAME=	XML-NamespaceSupport-1.07
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl module to the SAX2 NamespaceSupport class

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/XML/NamespaceSupport/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
