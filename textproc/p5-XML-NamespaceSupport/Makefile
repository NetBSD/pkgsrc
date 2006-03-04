# $NetBSD: Makefile,v 1.13 2006/03/04 21:30:50 jlam Exp $

DISTNAME=	XML-NamespaceSupport-1.09
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-NamespaceSupport/
COMMENT=	Perl module to the SAX2 NamespaceSupport class

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/XML/NamespaceSupport/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
