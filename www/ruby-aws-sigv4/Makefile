# $NetBSD: Makefile,v 1.6 2023/10/29 16:21:09 taca Exp $

DISTNAME=	aws-sigv4-1.6.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aws/aws-sdk-ruby
COMMENT=	AWS Signature Version 4 library
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-aws-eventstream>=1.0.2<2:../../www/ruby-aws-eventstream

USE_LANGUAGES=		# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
