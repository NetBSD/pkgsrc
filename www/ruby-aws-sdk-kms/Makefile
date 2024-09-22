# $NetBSD: Makefile,v 1.24 2024/09/22 07:51:40 taca Exp $

DISTNAME=	aws-sdk-kms-1.92.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aws/aws-sdk-ruby
COMMENT=	AWS SDK for Ruby - KMS
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-aws-sdk-core>=3.207<4:../../www/ruby-aws-sdk-core
#DEPENDS+=	${RUBY_PKGPREFIX}-aws-sigv4>=1.5<2:../../www/ruby-aws-sigv4

USE_LANGUAGES=		# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
